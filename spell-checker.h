#ifndef __SPELL_CHECKER_H
#define __SPELL_CHECKER_H

/**
 * This header file defines the function and type prototypes for
 * a spell-checking component to be implemented by the 
 * candidate. This file is provided by Surround.io and should 
 * not be modified as part of the solution. 
 *  
 * The assignment for the candidate is to author a single
 * vanilla C-compatible source file, "spell-checker.c" that 
 * includes this header file and provides an implementation for 
 * the functions described here. 
 *  
 * If you wish to include a "main" or a testing library, these 
 * functions should be placed in other source files. Only the 
 * implementation of the interface described here should be 
 * included in "spell-checker.c" 
 *  
 * The implementation of this module will provide a 
 * spell-checking capability that can be used by a calling 
 * module. Design considerations for the spell-checker include: 
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

/**
 * Abstract type used to represent a handle to a dictionary that 
 * is being constructed or is being used to spell-check. 
 */
struct _SpellCheckerDictionary;
typedef struct _SpellCheckerDictionary *SpellCheckerDictionaryHandle;

/**
 * Prototype for a callback function that is invoked by 
 * spellCheck() for each misspelled word found in the supplied 
 * text, in the order that such misspelled words appear in the 
 * text (including potential duplicates). This function is 
 * implemented by the caller of spellCheck(). 
 *  
 * @param unmatchedWord 
 *    A null-terminated character string containing a word that
 *    was not found in the dictionary. English alphabetic
 *    characters are trivially normalized to lower-case (A-Z are
 *    mapped to a-z, respectively). The word contains only
 *    characters in the range [0-9a-z] and extended characters
 *    in the range 0x80-0xFF.
 */
typedef void (*SpellCheckerCallback)(
    const char *unmatchedWord);

/**
 * This function creates a new, empty spell-checker dictionary 
 * to which new words can be added.
 * 
 * @return SpellCheckerDictionaryHandle 
 *             An opaque handle used to represent the dictionary
 *             in subsequent calls. The handle remains valid
 *             until closeSpellCheckerDictionary() is called.
 *  
 *             Returns NULL on error.
 */
SpellCheckerDictionaryHandle createSpellCheckerDictionary();

/**
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
int closeSpellCheckerDictionary(
    SpellCheckerDictionaryHandle dict);

/**
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
int spellCheckerAddWord(
    SpellCheckerDictionaryHandle dict,
    const char *word);

/**
 * Spellcheck a text document, using a dictionary previously 
 * created with spellCheckerCreateDictionary() and populated 
 * with spellCheckerAddWord(). For each misspelled word, invoke 
 * a callback function supplied by the caller, in the same order
 * in which the misspellings occur in the document. 
 * 
 * @param dict 
 *    An open dictionary handle previously returned from
 *    createSpellCheckerDictionary(), and populated with valid
 *    words using spellCheckerAddWord().
 *     
 * @param text 
 *    A null-terminated string containing text to be
 *    spell-checked. All characters other than those in the
 *    range [0-9a-zA-Z], or extended characters in the range
 *    0x80-0xFF, are considered to be delimeters that seperate
 *    words. Letters in the range [a-z] are considered to be
 *    equivalent to those in the range [A-Z] for the purposes of
 *    spelling.
 *  
 * @param callback 
 *    A function provided by the caller that should be invoked
 *    for each misspelled word in the provided text, in the same
 *    order in which the misspellings occur. Duplicate
 *    misspellings are not filtered out.
 */
void spellCheck(
    SpellCheckerDictionaryHandle dict,
    const char *text,
    SpellCheckerCallback callback);

#endif