// Author: http://lemming.life
// Language: D
// Description: a function to get an array of strings containing
//              the names or pathNames of file and folder/directories.
// Testing:
// - rdmd -unittest -main listFiles.d

string[] listFiles(alias isFunc)(string path, bool onlyBaseName = true) {
    import std.algorithm: filter, map;
    import std.array;
    import std.file: SpanMode, dirEntries;
    import std.path: baseName;

    return dirEntries(path, SpanMode.shallow)
        .filter!(a => isFunc(a))
        .map!(a=> onlyBaseName ? baseName(a.name) : a.name)
        .array;
}


// Test Driver
unittest{
    import std.algorithm: each;
    import std.file: getcwd, isDir, isFile;
    import std.stdio: writeln; 

    "\nList base names of files:".writeln;
    listFiles!(a => a.isFile)(getcwd).each!(s => s.writeln);

    "\nList full path of files:".writeln;
    listFiles!(a => a.isFile)(getcwd, false).each!(s => s.writeln);

    "\nList base names of directories:".writeln;
    listFiles!(a => a.isDir)(getcwd).each!(s => s.writeln);

    "\nList full path of directories:".writeln;
    listFiles!(a => a.isDir)(getcwd, false).each!(s => s.writeln);
}
