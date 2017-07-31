﻿// Author: http://lemming.life
// Language: C#
// Purpose: Tests my C# snippets
// Date: July 16, 2017

using System;
using Snippets;

// To setup in console do:
/*
dotnet new
dotnet restore
dotnet run
 */

namespace ConsoleApplication
{
    public class Program
    {
        public static void Main(string[] args)
        {
            const Boolean CONSOLE_INPUT = false;

            Console.WriteLine("\nTEST: C# Language");
            CsLanguage.executeDriver(CONSOLE_INPUT);

            Console.WriteLine("\nTEST: Maths");
            Maths.executeDriver();

            Console.WriteLine("\nTEST: Geometry");
            Geometry.executeDriver();

            //Console.WriteLine("\nTEST: Fibonacci");
            //Fibonacci.executeDriver();

            //Console.WriteLine("\nTEST: Palindrome");
            //Palindrome.executeDriver();

            Console.WriteLine("\nTEST: UrlParser");
            UrlParser.executeDriver();

            //Console.WriteLine("\nTEST: Reverse");
            //Reverse.executeDriver();
            Console.WriteLine("\nTEST: String Operations");
            StringOperations.executeDriver();

            Console.WriteLine("\nTEST: Challenge1");
            Challenges.Challenge1.executeDriver();

            Console.WriteLine("\nTEST: Challenge2");
            Challenges.Challenge2.executeDriver();

            // Since user input is required,
            // it is best to keep commented for now.
            if (CONSOLE_INPUT) {
                Console.WriteLine("\nTEST: Input");
                Input.executeDriver();
            }
           
        }
    }
}
