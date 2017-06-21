/*
Author: http://lemming.life
Project: fileBacker.d
Date: June 21, 2017
Language: D
Compile tool: rdmd from http://dlang.org
Details:
 - Copy files from source drive to destination drive.
 - If source and destination file modified-times are different then override.
 - Remove files found in destination that are not in source.
 - Keeps log as backupLog.txt

To compile:
rdmd --build-only fileBacker.d

To run (on Windows), where D: and E: are the source and destination drives, respectively.
fileBacker.exe D: E:
*/

import std.file: append, copy, DirEntry, dirEntries, exists, isDir, mkdir, remove, rmdirRecurse, SpanMode;
import std.datetime;
import std.conv: to;
import std.stdio: writeln;
import std.exception; 

void main(string[] args) {
    if (args.length != 3) return;
    string[] messages;
    int copyCount, removedFileCount, removedFolderCount;

    // Write the log
    scope(exit) {
        auto backupLog = "backupLog.txt";
        append(backupLog, "BACKUP START: " ~ (to!DateTime(Clock.currTime)).toSimpleString);
        append(backupLog, "Files/folders copied: " ~ to!string(copyCount));
        append(backupLog, "Removed files count: " ~ to!string(removedFileCount));
        append(backupLog, "Removed folders count: " ~ to!string(removedFolderCount));

        if (messages.length>0) {
            foreach(message; messages) {
                append(backupLog, message);
            }
        }
        append(backupLog, "BACKUP COMPLETED: " ~ (to!DateTime(Clock.currTime)).toSimpleString);
    }

    // For readability
    string sourceDrive = args[1];
    string destinationDrive = args[2];

    // Copy files from source drive to destination drive.
    // If source and destination file modified-times are different then override.
    foreach(sourceFile; dirEntries(sourceDrive, SpanMode.breadth)) {
        string destinationFile = destinationDrive ~ sourceFile[destinationDrive.length .. $];
        try {
            if ( sourceFile.isDir && !destinationFile.exists ) { destinationFile.mkdir; ++copyCount; }

            if ( sourceFile.isFile ) {
                if ( destinationFile.exists )  {
                    auto sourceTime = sourceFile.timeLastModified;
                    auto destinationTime = (new DirEntry(destinationFile)).timeLastModified;

                    if ( sourceTime != destinationTime ) {
                        remove(destinationFile);
                        copy(sourceFile, destinationFile);
                        ++copyCount;
                    }
                } else {
                    copy(sourceFile, destinationFile);
                    ++copyCount;
                }
            }
        } catch (Exception e) {
            messages ~= " - Failed to copy: " ~ sourceFile;
        }
    }

    // Remove files found in destination that are not in source.
    foreach(destinationFile; dirEntries(sourceDrive, SpanMode.breadth)) {
        string sourceFile = destinationDrive ~ destinationFile[sourceDrive.length .. $];
        try {
            if ( !sourceFile.exists ) {
                if ( destinationFile.isFile ) { remove(destinationFile); ++removedFileCount; }
                if ( destinationFile.isDir ) { rmdirRecurse(destinationFile); ++removedFolderCount; }
            }
        } catch (Exception e) {
            messages ~= " - Failed to remove: " ~ sourceFile;
        }
    }
}