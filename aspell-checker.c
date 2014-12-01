/*google "glibc vs. stdio.h" -->
http://crasseux.com/books/ctutorial/Header-files.html
The most commonly used header file is for the standard input/output routines in glibc and is called stdio.h. This and other header files are included with the #include command at the top of a source code file.
----
google "using underscores in c header files" -->

https://gcc.gnu.org/onlinedocs/cpp/Once-Only-Headers.html#Once-Only-Headers
In a system header file, it should begin with ‘__’ to avoid conflicts with user programs. In any kind of header file, the macro name should contain the name of the file and some additional text, to avoid conflicts with other header files.

----
http://www.gnu.org/software/libc/manual/html_node/Reserved-Names.html
In addition to the names documented in this manual,
reserved names include
all external identifiers (global functions and variables)
that begin with an underscore (‘_’)
and all identifiers regardless of use
that begin with either two underscores
or an underscore followed by a capital letter
are reserved names.
This is so that the library and header files can define functions,
variables, and macros for internal purposes
without risk of conflict with names in user programs.
----
http://en.wikipedia.org/wiki/Include_guard
(However, names starting with one or two underscores, such as _GRANDFATHER_H and __GRANDFATHER_H, are reserved to the implementation and must not be used by the user.[1][2]) It is important to avoid duplicating the name in different header files, as including one will prevent the symbols in the other being defined.

----
http://www.umich.edu/~eecs381/handouts/CHeaderFileGuidelines.pdf
Rule #2. Always use “include guards” in a header file. The most compact form uses #ifndef. Choose a guard symbol based
on the header file name, since these symbols are easy to think up and the header file names are almost always unique in a project.
Follow the convention of making the symbol all-caps. For example “Geometry_base.h” would start with:
#ifndef GEOMETRY_BASE_H
#define GEOMETRY_BASE_H
and end with:
#endif
Note: Do not start the guard symbol with an underscore! Leading underscore names are reserved for internal use by the C
implementation – the preprocessor, compiler, and Standard Library – breaking this rule can cause unnecessary and very puzzling
errors. The complete rule for leading underscores is rather complex; but if you follow this simple form you'll stay out of trouble.

#ifndef __SPELL_CHECKER_H
#define __SPELL_CHECKER_H

struct _SpellCheckerDictionary;
typedef struct _SpellCheckerDictionary *SpellCheckerDictionaryHandle;

typedef void (*SpellCheckerCallback)(const char *unmatchedWord);

SpellCheckerDictionaryHandle createSpellCheckerDictionary();

int closeSpellCheckerDictionary(SpellCheckerDictionaryHandle dict);

int spellCheckerAddWord(
    SpellCheckerDictionaryHandle dict,
    const char *word);

void spellCheck(
    SpellCheckerDictionaryHandle dict,
    const char *text,
    SpellCheckerCallback callback);

#endif
*/

/* Defines function and type prototypes for a spell-checking component.
 *
 * If you wish to include a "main" or a testing library, these 
 * functions should be placed in other source files. Only the 
 * implementation of the interface described here should be 
 * included in "spell-checker.c" 

 * a vanilla C-compatible source file that implements the functions described in the header file provided by Surround.io. 
 *  

 *  this module implements a spell-checking capability that can be used by a calling module. 
 Design considerations for the spell-checker include: 
 *     1. It should scale to a large word dictionary (on the
 *     order of the size of the English language)
 *     2. It should optimize for efficiency of spell-checking
 *     a large number of large documents with a single
 *     dictionary.
 *     3. Memory efficiency of the dictionary and cost of
 *     building the dictionary are considerations, but are
 *     secondary to performance of spell-checking.
 *     4. Use of 3rd-party functions and libraries is
 *     prohibited, other than the basic functions provided by
 *     glibc.
 **/


/* SpellCheckerCallback
callback function that is invoked by spellCheck() and 
 * implemented by the caller of spellCheck()
 * @param unmatchedWord 
 */

/** createSpellCheckerDictionary
 * This function creates a new, empty spell-checker dictionary 
 * to which new words can be added.
 */

/*
create dictionary with spellCheckerCreateDictionary() 
populate dictionary with spellCheckerAddWord()
Spellcheck a text document using that dictionary by invoking callback function
 */

/**closeSpellCheckerDictionary
 * Closes a dictionary previously created with 
 * createSpellCheckerDictionary(). All resources associated with 
 * the dictionary are freed, and the handle becomes invalid. 
 * 
 * @param dict 
 *    An open dictionary handle previously created with
 *    createSpellCheckerDictionary().
 *  
 * @return int 
 *    0 if the handle was successfully closed. -1 on error.
 */

 /** spellCheckerAddWord
 * Adds a valid word to an open dictionary previously created 
 * with spellCheckerCreateDictionary(). 
 * 
 * @param dict 
 *    An open dictionary handle previously returned from
 *    createSpellCheckerDictionary().
 *  
 * @param word 
 *    A null-terminated string containing a valid word to be
 *    added to the dictionary. Letters in the range [A-Z] are
 *    treated as equivalent to those in the range [a-z]. The
 *    word must contain only letters in the range [0-9a-zA-Z]
 *    and extended characters in the range 0x80-0xFF, or the
 *    word is rejected and false is returned. The word may be a
 *    duplicate of a word already in the dictionary, in which
 *    case it is accepted without error or effect.
 * 
 * @return int 
 *    0 if the word was accepted and either already existed in
 *    the dictionary or was successfully added. -1 otherwise.
 */
