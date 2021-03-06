// Req 4:   Use of 3rd-party functions and libraries is prohibited,
//          other than the basic functions provided by glibc.
#include <stdio.h>

// Include header file provided by Surround.io
#include "spell-checker.h"



/* You just misspelled me / and this is crazy / so when that happens / just call me maybe */
//void callback(char* word) {
//    printf("Word is fail: '%s'\n", word);
//}
SpellCheckerCallback callback(char *unmatchedWord)
{
    // Precondition: Assume character string unmatchedWord is null-terminated
    
    // Trivially normalize all letters by transform to lowercase
    // i.e. A-Z mapped to a-z
    
    // Check that the word contains only characters in the range
    // between [a-z] (i.e. A-Z), [0-9], and [0x80-0xFF].
    
    // All other characters
    // are considered to be delimeters that seperate words.
    
    printf("Word is fail: '%s'\n", unmatchedWord);
    
    return 0;
}

/*
 spell-checker.c:45:34: warning: incompatible pointer types passing
 'SpellCheckerCallback (char *)' to parameter of type
 'SpellCheckerCallback' (aka 'void (*)(const char *)')
 [-Wincompatible-pointer-types]
 spellCheck(dictionary, text, callback); // SpellCheckerCallback callback
 ^~~~~~~~
 ./spell-checker.h:145:26: note: passing argument to parameter 'callback' here
 SpellCheckerCallback callback);
 ^
 1 warning generated.
 lizz-natalia:relearning-c lizz$

 */


int main()
{
    printf("This is the start of the main function.\n");
 
    SpellCheckerDictionaryHandle dictionary = createSpellCheckerDictionary();
    
    // Read words in from a provided file
    const char *word = "hello";
    spellCheckerAddWord(dictionary, word);

    // Read in another file to spell-check
    const char *text = "hi hello hey heLLo";
    spellCheck(dictionary, text, callback); // SpellCheckerCallback callback
    
    closeSpellCheckerDictionary(dictionary);
    return 0;
};

//
//
//
void spellCheck(SpellCheckerDictionaryHandle dict,
                const char *text,
                SpellCheckerCallback callback)
{
    printf("function: spellCheck \n");
    
    /*
     * Design considerations for the spell-checker include:
     Req 1:     Spell-checker should scale to a large word dictionary
     (on the order of the size of the English language, i.e. ~200,000)
     
     *     3. Memory efficiency of the dictionary and cost of
     *     building the dictionary are considerations, but are
     *     secondary to performance of spell-checking.
     
     Req 2:     Optimize for efficiency of spell-checking
     a large number of large documents with a single dictionary
     
     1. Scalable to large word dictionary
     3. performance of spell checking first, second is mem efficiency and cost of building dict
     */
    
}


//
// struct _SpellCheckerDictionary
// Abstract type to represent a handle to a dictionary
// that is being constructed or is being used to spell-check.
//
/*
struct _SpellCheckerDictionary *SpellCheckerDictionaryHandle
{
    
   // _SpellCheckerDictionary
};
*/






//
// Creates a new, empty spell-checker dictionary to which new words can be added.
//
// Returns an opaque handle used to represent the dictionary in subsequent calls.
//
SpellCheckerDictionaryHandle createSpellCheckerDictionary()
{
    printf("function: createSpellCheckerDictionary \n");
    
    SpellCheckerDictionaryHandle dict = NULL;
    
    // Handle remains valid until closeSpellCheckerDictionary() is called.
    int valid = 1;
    
    
    // Returns NULL on error.
    return dict;
    
    
    // .......... what types of errors....??

}


//
//
//
int spellCheckerAddWord(SpellCheckerDictionaryHandle dict,
                        const char *word)
{
    printf("function: spellCheckerAddWord \n");
    
    
    // If the word is already in the dictionary,
    // accept it without error or effect.
    
    
    // The word must contain only letters in the range [0-9a-zA-Z]
    // and extended characters in the range 0x80-0xFF,
    // or the word is rejected and false is returned.
    return 0; //return false;
}


//
//
//
int closeSpellCheckerDictionary(SpellCheckerDictionaryHandle dict)
{
    printf("function: closeSpellCheckerDictionary \n");
    
    // Flag if the handle was successfully closed
    // returns 0 on success, -1 on error
    int success = -1;
  
    
    // Free all resources associated with the dictionary,
    // malloc...
    
    // and the handle becomes invalid.
    
    // Check that the handle was still valid
    // ....invalidate the handle....
    // SpellCheckerDictionaryHandle becomes invalid
    
    
    // Dictionary was successfully closed
    success = 0;
    
    return success;
}



