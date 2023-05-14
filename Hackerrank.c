
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#define MAX_CHARACTERS 1005
#define MAX_PARAGRAPHS 5

struct word {
    char* data;
};

struct sentence {
    struct word* data;
    int word_count;//denotes number of words in a sentence
};

struct paragraph {
    struct sentence* data  ;
    int sentence_count;//denotes number of sentences in a paragraph
};

struct document {
    struct paragraph* data;
    int paragraph_count;//denotes number of paragraphs in a document
};

struct document get_document(char* text) {
     struct document doc;

    int pcount = 0;
    for(int i = 0; i < strlen(text) ; i ++) {
        if(text[i] == '\n') pcount ++;
    }
    pcount ++;

    doc.paragraph_count = pcount;
    doc.data = malloc(pcount * sizeof(struct paragraph));

    for(int n = 0, m = 0, l = 0, i = 0; i < pcount; i ++) {
        int scount = 0;
        while(text[n] != '\n' && n < strlen(text)) {
            if(text[n] == '.') scount ++;
            n ++;
        }
        n ++;

        doc.data[i].sentence_count = scount;
        doc.data[i].data = malloc(scount * sizeof(struct sentence));

        for(int j = 0; j < scount; j ++) {
            int wcount = 0;
            while(text[m] != '.' && m < n) {
                if(text[m] == ' ') wcount ++;
                m ++;
            }
            m ++;
            if(text[m] == '\n') m ++;
            wcount ++;

            doc.data[i].data[j].word_count = wcount;
            doc.data[i].data[j].data = malloc(wcount * sizeof(struct word));

            for(int k = 0; k < wcount; k ++) {
                int ccount = 0;
                while(text[l] != ' ' && text[l] != '.' && l < m) {
                    ccount ++;
                    l ++;
                }
                l ++;
                if(text[l] == '\n') l ++;

                ccount ++;
                doc.data[i].data[j].data[k].data = malloc(ccount * sizeof(char));
            }
        }
    }

    int r = 0;
    for(int i = 0; i < doc.paragraph_count; i ++) {
        for(int j = 0; j < doc.data[i].sentence_count; j ++) {
            for(int k = 0; k < doc.data[i].data[j].word_count; k ++) {
                int l = 0;
                while(text[r] != ' ' && text[r] != '.' && text[r] != '\n') {
                    doc.data[i].data[j].data[k].data[l] = text[r];
                    r++;
                    l++;
                }
                doc.data[i].data[j].data[k].data[l] = '\0';
                if(text[r] == '.') {
                    r++;
                    break;
                }
                r ++;
            }
            if(text[r] == '\n') {
                r ++;
                break;
            }
        }
    }

    return doc;
}

struct word kth_word_in_mth_sentence_of_nth_paragraph(struct document Doc, int k, int m, int n) {
    return Doc.data[n - 1].data[m - 1].data[k - 1];
}

struct sentence kth_sentence_in_mth_paragraph(struct document Doc, int k, int m) { 
    return Doc.data[m - 1].data[k - 1];
}

struct paragraph kth_paragraph(struct document Doc, int k) {
    return Doc.data[k - 1];
}


void print_word(struct word w) {
    printf("%s", w.data);
}

void print_sentence(struct sentence sen) {
    for(int i = 0; i < sen.word_count; i++) {
        print_word(sen.data[i]);
        if (i != sen.word_count - 1) {
            printf(" ");
        }
    }
}

void print_paragraph(struct paragraph para) {
    for(int i = 0; i < para.sentence_count; i++){
        print_sentence(para.data[i]);
        printf(".");
    }
}

void print_document(struct document doc) {
    for(int i = 0; i < doc.paragraph_count; i++) {
        print_paragraph(doc.data[i]);
        if (i != doc.paragraph_count - 1)
            printf("\n");
    }
}

char* get_input_text() {	
    int paragraph_count;
    scanf("%d", &paragraph_count);

    char p[MAX_PARAGRAPHS][MAX_CHARACTERS], doc[MAX_CHARACTERS];
    memset(doc, 0, sizeof(doc));
    getchar();
    for (int i = 0; i < paragraph_count; i++) {
        scanf("%[^\n]%*c", p[i]);
        strcat(doc, p[i]);
        if (i != paragraph_count - 1)
            strcat(doc, "\n");
    }

    char* returnDoc = (char*)malloc((strlen (doc)+1) * (sizeof(char)));
    strcpy(returnDoc, doc);
    return returnDoc;
}

int main() 
{
    char* text = get_input_text();
    struct document Doc = get_document(text);

    int q;
    scanf("%d", &q);

    while (q--) {
        int type;
        scanf("%d", &type);

        if (type == 3){
            int k, m, n;
            scanf("%d %d %d", &k, &m, &n);
            struct word w = kth_word_in_mth_sentence_of_nth_paragraph(Doc, k, m, n);
            print_word(w);
        }

        else if (type == 2) {
            int k, m;
            scanf("%d %d", &k, &m);
            struct sentence sen= kth_sentence_in_mth_paragraph(Doc, k, m);
            print_sentence(sen);
        }

        else{
            int k;
            scanf("%d", &k);
            struct paragraph para = kth_paragraph(Doc, k);
            print_paragraph(para);
        }
        printf("\n");
    }     
}
 1 change: 1 addition & 0 deletions1  
README.md
@@ -1,43 +1,44 @@
# HackerRank	# HackerRank
[![My hackerrank profile](images/HackerRankLogo.svg)](https://www.hackerrank.com/pr_chandrapraka2)	[![My hackerrank profile](images/HackerRankLogo.svg)](https://www.hackerrank.com/pr_chandrapraka2)
Solutions to some problems on Hackerrank.	Solutions to some problems on Hackerrank.
* [LANGUAGE PROFICIENCY](#language-proficiency)	* [LANGUAGE PROFICIENCY](#language-proficiency)
    * [C](#c)	    * [C](#c)
    * [C++](#c++)	    * [C++](#c++)
    * [Java](#java)	    * [Java](#java)
    * [Python](#python)	    * [Python](#python)
    * [Shell](#shell)	    * [Shell](#shell)
# LANGUAGE PROFICIENCY	# LANGUAGE PROFICIENCY
# C	# C
| Subdomain | Difficulty | Challenge | Solution |	| Subdomain | Difficulty | Challenge | Solution |
|:--:|:--:|:--:|:--:|	|:--:|:--:|:--:|:--:|
| Introduction | Easy | ["Hello World!" in C](https://www.hackerrank.com/challenges/hello-world-c/problem) | [HelloWorld.c](LANGUAGE%20PROFICIENCY/C/Introduction/HelloWorld.c) |	| Introduction | Easy | ["Hello World!" in C](https://www.hackerrank.com/challenges/hello-world-c/problem) | [HelloWorld.c](LANGUAGE%20PROFICIENCY/C/Introduction/HelloWorld.c) |
| Introduction | Easy | [Playing With Characters](https://www.hackerrank.com/challenges/playing-with-characters/problem) | [PlayingWithCharacters.c](LANGUAGE%20PROFICIENCY/C/Introduction/PlayingWithCharacters.c)	| Introduction | Easy | [Playing With Characters](https://www.hackerrank.com/challenges/playing-with-characters/problem) | [PlayingWithCharacters.c](LANGUAGE%20PROFICIENCY/C/Introduction/PlayingWithCharacters.c)
| Introduction | Easy | [Sum and Difference of Two Numbers](https://www.hackerrank.com/challenges/sum-numbers-c/problem) | [SumAndDifferenceOfTwoNumbers.c](LANGUAGE%20PROFICIENCY/C/Introduction/SumAndDifferenceOfTwoNumbers.c)	| Introduction | Easy | [Sum and Difference of Two Numbers](https://www.hackerrank.com/challenges/sum-numbers-c/problem) | [SumAndDifferenceOfTwoNumbers.c](LANGUAGE%20PROFICIENCY/C/Introduction/SumAndDifferenceOfTwoNumbers.c)
| Introduction | Easy | [Functions in C](https://www.hackerrank.com/challenges/functions-in-c/problem) | [FunctionsInC.c](LANGUAGE%20PROFICIENCY/C/Introduction/FunctionsInC.c)	| Introduction | Easy | [Functions in C](https://www.hackerrank.com/challenges/functions-in-c/problem) | [FunctionsInC.c](LANGUAGE%20PROFICIENCY/C/Introduction/FunctionsInC.c)
| Introduction | Easy | [Pointers in C](https://www.hackerrank.com/challenges/pointer-in-c/problem) | [PointersInC.c](LANGUAGE%20PROFICIENCY/C/Introduction/PointersInC.c)	| Introduction | Easy | [Pointers in C](https://www.hackerrank.com/challenges/pointer-in-c/problem) | [PointersInC.c](LANGUAGE%20PROFICIENCY/C/Introduction/PointersInC.c)
| Conditionals and Loops | Easy | [Conditional Statements in C](https://www.hackerrank.com/challenges/conditional-statements-in-c/problem) | [ConditionalStatementsInC.c](LANGUAGE%20PROFICIENCY/C/Conditionals%20and%20Loops/ConditionalStatementsInC.c)	| Conditionals and Loops | Easy | [Conditional Statements in C](https://www.hackerrank.com/challenges/conditional-statements-in-c/problem) | [ConditionalStatementsInC.c](LANGUAGE%20PROFICIENCY/C/Conditionals%20and%20Loops/ConditionalStatementsInC.c)
| Conditionals and Loops | Easy | [For Loop in C](https://www.hackerrank.com/challenges/for-loop-in-c/problem) | [ForLoopInC.c](LANGUAGE%20PROFICIENCY/C/Conditionals%20and%20Loops/ForLoopInC.c)	| Conditionals and Loops | Easy | [For Loop in C](https://www.hackerrank.com/challenges/for-loop-in-c/problem) | [ForLoopInC.c](LANGUAGE%20PROFICIENCY/C/Conditionals%20and%20Loops/ForLoopInC.c)
| Conditionals and Loops | Easy | [Sum of Digits of a Five Digit Number](https://www.hackerrank.com/challenges/sum-of-digits-of-a-five-digit-number/copy-from/98583090) | [SumOfDigitsOfAFiveDigitNumber.c](LANGUAGE%20PROFICIENCY/C/Conditionals%20and%20Loops/SumOfDigitsOfAFiveDigitNumber.c)	| Conditionals and Loops | Easy | [Sum of Digits of a Five Digit Number](https://www.hackerrank.com/challenges/sum-of-digits-of-a-five-digit-number/copy-from/98583090) | [SumOfDigitsOfAFiveDigitNumber.c](LANGUAGE%20PROFICIENCY/C/Conditionals%20and%20Loops/SumOfDigitsOfAFiveDigitNumber.c)
| Conditionals and Loops | Easy | [Bitwise Operators](https://www.hackerrank.com/challenges/bitwise-operators-in-c/problem) | [BitwiseOperators.c](LANGUAGE%20PROFICIENCY/C/Conditionals%20and%20Loops/BitwiseOperators.c)	| Conditionals and Loops | Easy | [Bitwise Operators](https://www.hackerrank.com/challenges/bitwise-operators-in-c/problem) | [BitwiseOperators.c](LANGUAGE%20PROFICIENCY/C/Conditionals%20and%20Loops/BitwiseOperators.c)
| Conditionals and Loops | Medium | [Printing Pattern using Loops](https://www.hackerrank.com/challenges/printing-pattern-2/problem) | [PrintingPatternsUsingLoops.c](LANGUAGE%20PROFICIENCY/C/Conditionals%20and%20Loops/PrintingPatternsUsingLoops.c)	| Conditionals and Loops | Medium | [Printing Pattern using Loops](https://www.hackerrank.com/challenges/printing-pattern-2/problem) | [PrintingPatternsUsingLoops.c](LANGUAGE%20PROFICIENCY/C/Conditionals%20and%20Loops/PrintingPatternsUsingLoops.c)
| Arrays and Strings | Medium | [1D Arrays in C](https://www.hackerrank.com/challenges/1d-arrays-in-c/problem) | [1DArraysInC.c](LANGUAGE%20PROFICIENCY/C/Arrays%20and%20Strings/1DArraysInC.c)	| Arrays and Strings | Medium | [1D Arrays in C](https://www.hackerrank.com/challenges/1d-arrays-in-c/problem) | [1DArraysInC.c](LANGUAGE%20PROFICIENCY/C/Arrays%20and%20Strings/1DArraysInC.c)
| Arrays and Strings | Medium | [Array Reversal](https://www.hackerrank.com/challenges/reverse-array-c/problem) | [ArrayReversal.c](LANGUAGE%20PROFICIENCY/C/Arrays%20and%20Strings/ArrayReversal.c)	| Arrays and Strings | Medium | [Array Reversal](https://www.hackerrank.com/challenges/reverse-array-c/problem) | [ArrayReversal.c](LANGUAGE%20PROFICIENCY/C/Arrays%20and%20Strings/ArrayReversal.c)
| Arrays and Strings | Medium | [Digit Frequency](https://www.hackerrank.com/challenges/frequency-of-digits-1/problem)|[DigitFrequency.c](LANGUAGE%20PROFICIENCY/C/Arrays%20and%20Strings/DigitFrequency.c)	| Arrays and Strings | Medium | [Digit Frequency](https://www.hackerrank.com/challenges/frequency-of-digits-1/problem)|[DigitFrequency.c](LANGUAGE%20PROFICIENCY/C/Arrays%20and%20Strings/DigitFrequency.c)
| Arrays and Strings | Medium | [Printing Tokens](https://www.hackerrank.com/challenges/printing-tokens-/problem) | [PrintingTokens.c](LANGUAGE%20PROFICIENCY/C/Arrays%20and%20Strings/PrintingTokens.c)	| Arrays and Strings | Medium | [Printing Tokens](https://www.hackerrank.com/challenges/printing-tokens-/problem) | [PrintingTokens.c](LANGUAGE%20PROFICIENCY/C/Arrays%20and%20Strings/PrintingTokens.c)
| Arrays and Strings | Medium | [Dynamic Array in C](https://www.hackerrank.com/challenges/dynamic-array-in-c/problem) | [DynamicArrayInC.c](LANGUAGE%20PROFICIENCY/C/Arrays%20and%20Strings/DynamicArrayInC.c)	| Arrays and Strings | Medium | [Dynamic Array in C](https://www.hackerrank.com/challenges/dynamic-array-in-c/problem) | [DynamicArrayInC.c](LANGUAGE%20PROFICIENCY/C/Arrays%20and%20Strings/DynamicArrayInC.c)
| Functions | Easy | [Calculate the Nth term](https://www.hackerrank.com/challenges/recursion-in-c/problem) | [CalculateTheNthTerm.c](LANGUAGE%20PROFICIENCY/C/Functions/CalculateTheNthTerm.c)	| Functions | Easy | [Calculate the Nth term](https://www.hackerrank.com/challenges/recursion-in-c/problem) | [CalculateTheNthTerm.c](LANGUAGE%20PROFICIENCY/C/Functions/CalculateTheNthTerm.c)
| Functions | Easy | [Students Marks Sum](https://www.hackerrank.com/challenges/students-marks-sum/problem) | [StudentsMarksSum.c](LANGUAGE%20PROFICIENCY/C/Functions/StudentsMarksSum.c)	| Functions | Easy | [Students Marks Sum](https://www.hackerrank.com/challenges/students-marks-sum/problem) | [StudentsMarksSum.c](LANGUAGE%20PROFICIENCY/C/Functions/StudentsMarksSum.c)
| Functions | Hard | [Sorting Array of Strings](https://www.hackerrank.com/challenges/sorting-array-of-strings/problem) | [SortingArrayOfStrings.py](LANGUAGE%20PROFICIENCY/C/Functions/SortingArrayOfStrings.py)	| Functions | Hard | [Sorting Array of Strings](https://www.hackerrank.com/challenges/sorting-array-of-strings/problem) | [SortingArrayOfStrings.py](LANGUAGE%20PROFICIENCY/C/Functions/SortingArrayOfStrings.py)
| Functions | Medium | [Permutations of Strings](https://www.hackerrank.com/challenges/permutations-of-strings/problem) | [PermutationsOfStrings.c](LANGUAGE%20PROFICIENCY/C/Functions/PermutationsOfStrings.c)	| Functions | Medium | [Permutations of Strings](https://www.hackerrank.com/challenges/permutations-of-strings/problem) | [PermutationsOfStrings.c](LANGUAGE%20PROFICIENCY/C/Functions/PermutationsOfStrings.c)
| Functions | Medium | [Variadic functions in C](https://www.hackerrank.com/challenges/variadic-functions-in-c/problem) | [VariadicFunctionsInC.c](LANGUAGE%20PROFICIENCY/C/Functions/VariadicFunctionsInC.c)	| Functions | Medium | [Variadic functions in C](https://www.hackerrank.com/challenges/variadic-functions-in-c/problem) | [VariadicFunctionsInC.c](LANGUAGE%20PROFICIENCY/C/Functions/VariadicFunctionsInC.c)
| Functions | Hard | [Querying the Document](https://www.hackerrank.com/challenges/querying-the-document/problem) | [QueryingTheDocument.c](LANGUAGE%20PROFICIENCY/C/Functions/QueryingTheDocument.c)	| Functions | Hard | [Querying the Document](https://www.hackerrank.com/challenges/querying-the-document/problem) | [QueryingTheDocument.c](LANGUAGE%20PROFICIENCY/C/Functions/QueryingTheDocument.c)
| Structs and Enums | Easy | [Boxes through a Tunnel](https://www.hackerrank.com/challenges/too-high-boxes/problem) | [BoxesThroughATunnel.c](LANGUAGE%20PROFICIENCY/C/Structs%20and%20Enums/BoxesThroughATunnel.c)	| Structs and Enums | Easy | [Boxes through a Tunnel](https://www.hackerrank.com/challenges/too-high-boxes/problem) | [BoxesThroughATunnel.c](LANGUAGE%20PROFICIENCY/C/Structs%20and%20Enums/BoxesThroughATunnel.c)
| Structs and Enums | Medium | [Small Triangles, Large Triangles](https://www.hackerrank.com/challenges/small-triangles-large-triangles/problem) | [SmallTrianglesLargeTriangles.cpp](LANGUAGE%20PROFICIENCY/C/Structs%20and%20Enums/SmallTrianglesLargeTriangles.cpp)	| Structs and Enums | Medium | [Small Triangles, Large Triangles](https://www.hackerrank.com/challenges/small-triangles-large-triangles/problem) | [SmallTrianglesLargeTriangles.cpp](LANGUAGE%20PROFICIENCY/C/Structs%20and%20Enums/SmallTrianglesLargeTriangles.cpp)
| Structs and Enums | Hard | [Post Transition](https://www.hackerrank.com/challenges/post-transition/problem) | [PostTransition.c](LANGUAGE%20PROFICIENCY/C/Structs%20and%20Enums/PostTransition.c)	| Structs and Enums | Hard | [Post Transition](https://www.hackerrank.com/challenges/post-transition/problem) | [PostTransition.c](LANGUAGE%20PROFICIENCY/C/Structs%20and%20Enums/PostTransition.c)
| Structs and Enums | Hard | [Structuring the Document](https://www.hackerrank.com/challenges/structuring-the-document/problem) | [StructuringTheDocument.c](LANGUAGE%20PROFICIENCY/C/Structs%20and%20Enums/)




# C++	# C++
| Subdomain | Difficulty | Challenge | Solution |	| Subdomain | Difficulty | Challenge | Solution |
|:--:|:--:|:--:|:--:|	|:--:|:--:|:--:|:--:|
| Introduction | Easy | [Say "Hello, World!" With C++](https://www.hackerrank.com/challenges/cpp-hello-world/problem) | [SayHelloWorldWithCPlusPlus.cpp]( LANGUAGE%20PROFICIENCY/C%2B%2B/Introduction/SayHelloWorldWithCPlusPlus.cpp)	| Introduction | Easy | [Say "Hello, World!" With C++](https://www.hackerrank.com/challenges/cpp-hello-world/problem) | [SayHelloWorldWithCPlusPlus.cpp]( LANGUAGE%20PROFICIENCY/C%2B%2B/Introduction/SayHelloWorldWithCPlusPlus.cpp)
| Introduction | Easy | [Input and Output](https://www.hackerrank.com/challenges/cpp-input-and-output/problem) | [InputAndOutput.cpp](LANGUAGE%20PROFICIENCY/C%2B%2B/Introduction/InputAndOutput.cpp)	| Introduction | Easy | [Input and Output](https://www.hackerrank.com/challenges/cpp-input-and-output/problem) | [InputAndOutput.cpp](LANGUAGE%20PROFICIENCY/C%2B%2B/Introduction/InputAndOutput.cpp)
| Introduction | Easy | [Basic Data Types](https://www.hackerrank.com/challenges/c-tutorial-basic-data-types/problem) | [BasicDataTypes.cpp](LANGUAGE%20PROFICIENCY/C%2B%2B/Introduction/BasicDataTypes.cpp)	| Introduction | Easy | [Basic Data Types](https://www.hackerrank.com/challenges/c-tutorial-basic-data-types/problem) | [BasicDataTypes.cpp](LANGUAGE%20PROFICIENCY/C%2B%2B/Introduction/BasicDataTypes.cpp)
| Introduction | Easy | [Conditional Statements](https://www.hackerrank.com/challenges/c-tutorial-conditional-if-else/problem) | [ConditionalStatements.cpp](LANGUAGE%20PROFICIENCY/C%2B%2B/Introduction/ConditionalStatements.cpp)	| Introduction | Easy | [Conditional Statements](https://www.hackerrank.com/challenges/c-tutorial-conditional-if-else/problem) | [ConditionalStatements.cpp](LANGUAGE%20PROFICIENCY/C%2B%2B/Introduction/ConditionalStatements.cpp)
| Introduction | Easy | [For Loop](https://www.hackerrank.com/challenges/c-tutorial-for-loop/problem) | [ForLoop.cpp](LANGUAGE%20PROFICIENCY/C%2B%2B/Introduction/ForLoop.cpp)	| Introduction | Easy | [For Loop](https://www.hackerrank.com/challenges/c-tutorial-for-loop/problem) | [ForLoop.cpp](LANGUAGE%20PROFICIENCY/C%2B%2B/Introduction/ForLoop.cpp)
| Introduction | Easy | [Functions](https://www.hackerrank.com/challenges/c-tutorial-functions/problem) | [Functions.cpp](LANGUAGE%20PROFICIENCY/C%2B%2B/Introduction/Functions.cpp)	| Introduction | Easy | [Functions](https://www.hackerrank.com/challenges/c-tutorial-functions/problem) | [Functions.cpp](LANGUAGE%20PROFICIENCY/C%2B%2B/Introduction/Functions.cpp)
| Introduction | Easy | [Pointer](https://www.hackerrank.com/challenges/c-tutorial-pointer/problem) | [Pointer.cpp](LANGUAGE%20PROFICIENCY/C%2B%2B/Introduction/Pointer.cpp)	| Introduction | Easy | [Pointer](https://www.hackerrank.com/challenges/c-tutorial-pointer/problem) | [Pointer.cpp](LANGUAGE%20PROFICIENCY/C%2B%2B/Introduction/Pointer.cpp)
| Introduction | Easy | [Arrays Introduction](https://www.hackerrank.com/challenges/arrays-introduction/problem) | [ArraysIntroduction.cpp](LANGUAGE%20PROFICIENCY/C%2B%2B/Introduction/ArraysIntroduction.cpp)	| Introduction | Easy | [Arrays Introduction](https://www.hackerrank.com/challenges/arrays-introduction/problem) | [ArraysIntroduction.cpp](LANGUAGE%20PROFICIENCY/C%2B%2B/Introduction/ArraysIntroduction.cpp)
| Introduction | Easy | [Variable Sized Arrays](https://www.hackerrank.com/challenges/variable-sized-arrays/problem) | [VariableSizedArrays.cpp](LANGUAGE%20PROFICIENCY/C%2B%2B/Introduction/VariableSizedArrays.cpp)	| Introduction | Easy | [Variable Sized Arrays](https://www.hackerrank.com/challenges/variable-sized-arrays/problem) | [VariableSizedArrays.cpp](LANGUAGE%20PROFICIENCY/C%2B%2B/Introduction/VariableSizedArrays.cpp)
| Strings | Easy | [Strings](https://www.hackerrank.com/challenges/c-tutorial-strings/problem) | [Strings.cpp](LANGUAGE%20PROFICIENCY/C%2B%2B/Strings/Strings.cpp)	| Strings | Easy | [Strings](https://www.hackerrank.com/challenges/c-tutorial-strings/problem) | [Strings.cpp](LANGUAGE%20PROFICIENCY/C%2B%2B/Strings/Strings.cpp)
| Strings | Easy | [StringStream](https://www.hackerrank.com/challenges/c-tutorial-stringstream/problem) | [StringStream.cpp](LANGUAGE%20PROFICIENCY/C%2B%2B/Strings/StringStream.cpp)	| Strings | Easy | [StringStream](https://www.hackerrank.com/challenges/c-tutorial-stringstream/problem) | [StringStream.cpp](LANGUAGE%20PROFICIENCY/C%2B%2B/Strings/StringStream.cpp)
| Strings | Medium | [Attribute Parser](https://www.hackerrank.com/challenges/attribute-parser/problem) | [AttributeParser.cpp](LANGUAGE%20PROFICIENCY/C%2B%2B/Strings/AttributeParser.cpp)	| Strings | Medium | [Attribute Parser](https://www.hackerrank.com/challenges/attribute-parser/problem) | [AttributeParser.cpp](LANGUAGE%20PROFICIENCY/C%2B%2B/Strings/AttributeParser.cpp)
| Classes | Easy | [Structs](https://www.hackerrank.com/challenges/c-tutorial-struct/problem) | [Structs.cpp](LANGUAGE%20PROFICIENCY/C%2B%2B/Classes/Structs.cpp)	| Classes | Easy | [Structs](https://www.hackerrank.com/challenges/c-tutorial-struct/problem) | [Structs.cpp](LANGUAGE%20PROFICIENCY/C%2B%2B/Classes/Structs.cpp)
| Classes | Easy | [Class](https://www.hackerrank.com/challenges/c-tutorial-class/problem) | [Class.cpp](LANGUAGE%20PROFICIENCY/C%2B%2B/Classes/Class.cpp)	| Classes | Easy | [Class](https://www.hackerrank.com/challenges/c-tutorial-class/problem) | [Class.cpp](LANGUAGE%20PROFICIENCY/C%2B%2B/Classes/Class.cpp)
| Classes | Easy | [Classes and Objects](https://www.hackerrank.com/challenges/classes-objects/problem) | [ClassesAndObjects.cpp](LANGUAGE%20PROFICIENCY/C%2B%2B/Classes/ClassesAndObjects.cpp)	| Classes | Easy | [Classes and Objects](https://www.hackerrank.com/challenges/classes-objects/problem) | [ClassesAndObjects.cpp](LANGUAGE%20PROFICIENCY/C%2B%2B/Classes/ClassesAndObjects.cpp)
| Classes | Easy | [Box It!](https://www.hackerrank.com/challenges/box-it/problem) | [BoxIt.cpp](LANGUAGE%20PROFICIENCY/C%2B%2B/Classes/BoxIt.cpp)	| Classes | Easy | [Box It!](https://www.hackerrank.com/challenges/box-it/problem) | [BoxIt.cpp](LANGUAGE%20PROFICIENCY/C%2B%2B/Classes/BoxIt.cpp)
| Classes | Medium | [Inherited Code](https://www.hackerrank.com/challenges/inherited-code/problem) | [InheritedCode.cpp](LANGUAGE%20PROFICIENCY/C%2B%2B/Classes/InheritedCode.cpp)	| Classes | Medium | [Inherited Code](https://www.hackerrank.com/challenges/inherited-code/problem) | [InheritedCode.cpp](LANGUAGE%20PROFICIENCY/C%2B%2B/Classes/InheritedCode.cpp)
| Classes | Medium | [Exceptional Server](https://www.hackerrank.com/challenges/exceptional-server/problem) | [ExceptionalServer.cpp](LANGUAGE%20PROFICIENCY/C%2B%2B/Classes/ExceptionalServer.cpp)	| Classes | Medium | [Exceptional Server](https://www.hackerrank.com/challenges/exceptional-server/problem) | [ExceptionalServer.cpp](LANGUAGE%20PROFICIENCY/C%2B%2B/Classes/ExceptionalServer.cpp)
| Classes | Medium | [Virtual Functions](https://www.hackerrank.com/challenges/virtual-functions/problem) | [VirtualFunctions.cpp](LANGUAGE%20PROFICIENCY/C%2B%2B/Classes/VirtualFunctions.cpp)	| Classes | Medium | [Virtual Functions](https://www.hackerrank.com/challenges/virtual-functions/problem) | [VirtualFunctions.cpp](LANGUAGE%20PROFICIENCY/C%2B%2B/Classes/VirtualFunctions.cpp)
| Classes | Hard | [Abstract Classes - Polymorphism](https://www.hackerrank.com/challenges/abstract-classes-polymorphism/problem) |  [AbstractClassesPolymorphism.cpp](LANGUAGE%20PROFICIENCY/C%2B%2B/Classes/AbstractClassesPolymorphism.cpp)	| Classes | Hard | [Abstract Classes - Polymorphism](https://www.hackerrank.com/challenges/abstract-classes-polymorphism/problem) |  [AbstractClassesPolymorphism.cpp](LANGUAGE%20PROFICIENCY/C%2B%2B/Classes/AbstractClassesPolymorphism.cpp)
| Inheritance | Easy | [Inheritance Introduction](https://www.hackerrank.com/challenges/inheritance-introduction/problem) | [InheritanceIntroduction.cpp](LANGUAGE%20PROFICIENCY/C%2B%2B/Inheritance/InheritanceIntroduction.cpp)	| Inheritance | Easy | [Inheritance Introduction](https://www.hackerrank.com/challenges/inheritance-introduction/problem) | [InheritanceIntroduction.cpp](LANGUAGE%20PROFICIENCY/C%2B%2B/Inheritance/InheritanceIntroduction.cpp)
| Inheritance | Easy | [Rectangle Area](https://www.hackerrank.com/challenges/rectangle-area/problem) | [RectangleArea.cpp](LANGUAGE%20PROFICIENCY/C%2B%2B/Inheritance/RectangleArea.cpp)	| Inheritance | Easy | [Rectangle Area](https://www.hackerrank.com/challenges/rectangle-area/problem) | [RectangleArea.cpp](LANGUAGE%20PROFICIENCY/C%2B%2B/Inheritance/RectangleArea.cpp)
| Inheritance | Easy | [Multi Level Inheritance](https://www.hackerrank.com/challenges/multi-level-inheritance-cpp/problem) | [MultiLevelInheritance.cpp](LANGUAGE%20PROFICIENCY/C%2B%2B/Inheritance/MultiLevelInheritance.cpp)	| Inheritance | Easy | [Multi Level Inheritance](https://www.hackerrank.com/challenges/multi-level-inheritance-cpp/problem) | [MultiLevelInheritance.cpp](LANGUAGE%20PROFICIENCY/C%2B%2B/Inheritance/MultiLevelInheritance.cpp)
| Inheritance | Medium | [Accessing Inherited Functions](https://www.hackerrank.com/challenges/accessing-inherited-functions/problem) | [AccessingInheritedFunctions.cpp](LANGUAGE%20PROFICIENCY/C%2B%2B/Inheritance/AccessingInheritedFunctions.cpp)	| Inheritance | Medium | [Accessing Inherited Functions](https://www.hackerrank.com/challenges/accessing-inherited-functions/problem) | [AccessingInheritedFunctions.cpp](LANGUAGE%20PROFICIENCY/C%2B%2B/Inheritance/AccessingInheritedFunctions.cpp)
| Inheritance | Hard | [Magic Spells](https://www.hackerrank.com/challenges/magic-spells/problem) | [MagicSpells.cpp](LANGUAGE%20PROFICIENCY/C%2B%2B/Inheritance/MagicSpells.cpp)	| Inheritance | Hard | [Magic Spells](https://www.hackerrank.com/challenges/magic-spells/problem) | [MagicSpells.cpp](LANGUAGE%20PROFICIENCY/C%2B%2B/Inheritance/MagicSpells.cpp)
# Java	# Java
| Subdomain | Difficulty | Challenge | Solution |	| Subdomain | Difficulty | Challenge | Solution |
|:--:|:--:|:--:|:--:|	|:--:|:--:|:--:|:--:|
| Introduction | Easy | [Welcome to Java!](https://www.hackerrank.com/challenges/welcome-to-java/problem) |[WelcomeToJava.java](LANGUAGE%20PROFICIENCY/Java/Introduction/WelcomeToJava.java)	| Introduction | Easy | [Welcome to Java!](https://www.hackerrank.com/challenges/welcome-to-java/problem) |[WelcomeToJava.java](LANGUAGE%20PROFICIENCY/Java/Introduction/WelcomeToJava.java)
| Introduction | Easy | [Java Stdin and Stdout I](https://www.hackerrank.com/challenges/java-stdin-and-stdout-1/problem) | [JavaStdInAndStdOut1.java](LANGUAGE%20PROFICIENCY/Java/Introduction/JavaStdInAndStdOut1.java)	| Introduction | Easy | [Java Stdin and Stdout I](https://www.hackerrank.com/challenges/java-stdin-and-stdout-1/problem) | [JavaStdInAndStdOut1.java](LANGUAGE%20PROFICIENCY/Java/Introduction/JavaStdInAndStdOut1.java)
| Introduction | Easy |[Java If-Else](https://www.hackerrank.com/challenges/java-if-else/problem)| [JavaIfElse.java](LANGUAGE%20PROFICIENCY/Java/Introduction/JavaIfElse.java)	| Introduction | Easy |[Java If-Else](https://www.hackerrank.com/challenges/java-if-else/problem)| [JavaIfElse.java](LANGUAGE%20PROFICIENCY/Java/Introduction/JavaIfElse.java)
| Introduction | Easy | [Java Output Formatting](https://www.hackerrank.com/challenges/java-output-formatting/problem) | [JavaOutputFormatting.java](LANGUAGE%20PROFICIENCY/Java/Introduction/JavaOutputFormatting.java)	| Introduction | Easy | [Java Output Formatting](https://www.hackerrank.com/challenges/java-output-formatting/problem) | [JavaOutputFormatting.java](LANGUAGE%20PROFICIENCY/Java/Introduction/JavaOutputFormatting.java)
| Introduction | Easy | [Java Loops I](https://www.hackerrank.com/challenges/java-loops-i/problem) | [JavaLoops1.java](LANGUAGE%20PROFICIENCY/Java/Introduction/JavaLoops1.java)	| Introduction | Easy | [Java Loops I](https://www.hackerrank.com/challenges/java-loops-i/problem) | [JavaLoops1.java](LANGUAGE%20PROFICIENCY/Java/Introduction/JavaLoops1.java)
| Introduction | Easy | [Java Loops II](https://www.hackerrank.com/challenges/java-loops/problem) | [JavaLoops2.java](LANGUAGE%20PROFICIENCY/Java/Introduction/JavaLoops2.java)	| Introduction | Easy | [Java Loops II](https://www.hackerrank.com/challenges/java-loops/problem) | [JavaLoops2.java](LANGUAGE%20PROFICIENCY/Java/Introduction/JavaLoops2.java)
| Introduction | Easy | [Java Datatypes](https://www.hackerrank.com/challenges/java-datatypes/problem) | [JavaDatatypes.java](LANGUAGE%20PROFICIENCY/Java/Introduction/JavaDatatypes.java)	| Introduction | Easy | [Java Datatypes](https://www.hackerrank.com/challenges/java-datatypes/problem) | [JavaDatatypes.java](LANGUAGE%20PROFICIENCY/Java/Introduction/JavaDatatypes.java)
| Introduction | Easy | [Java End-of-file](https://www.hackerrank.com/challenges/java-end-of-file/problem) | [JavaEndOfFile.java](LANGUAGE%20PROFICIENCY/Java/Introduction/JavaEndOfFile.java)	| Introduction | Easy | [Java End-of-file](https://www.hackerrank.com/challenges/java-end-of-file/problem) | [JavaEndOfFile.java](LANGUAGE%20PROFICIENCY/Java/Introduction/JavaEndOfFile.java)
| Introduction | Easy | [Java Static Initializer Block](https://www.hackerrank.com/challenges/java-static-initializer-block/problem) | [JavaStaticInitializerBlock.java](LANGUAGE%20PROFICIENCY/Java/Introduction/JavaStaticInitializerBlock.java)	| Introduction | Easy | [Java Static Initializer Block](https://www.hackerrank.com/challenges/java-static-initializer-block/problem) | [JavaStaticInitializerBlock.java](LANGUAGE%20PROFICIENCY/Java/Introduction/JavaStaticInitializerBlock.java)
| Introduction | Easy | [Java Int to String](https://www.hackerrank.com/challenges/java-int-to-string/problem) | [JavaIntToString.java](LANGUAGE%20PROFICIENCY/Java/Introduction/JavaIntToString.java)	| Introduction | Easy | [Java Int to String](https://www.hackerrank.com/challenges/java-int-to-string/problem) | [JavaIntToString.java](LANGUAGE%20PROFICIENCY/Java/Introduction/JavaIntToString.java)
| Introduction | Easy | [Java Date and Time](https://www.hackerrank.com/challenges/java-date-and-time/problem) | [JavaDateAndTime.java](LANGUAGE%20PROFICIENCY/Java/Introduction/JavaDateAndTime.java)	| Introduction | Easy | [Java Date and Time](https://www.hackerrank.com/challenges/java-date-and-time/problem) | [JavaDateAndTime.java](LANGUAGE%20PROFICIENCY/Java/Introduction/JavaDateAndTime.java)
| Introduction | Easy | [Java Currency Formatter](https://www.hackerrank.com/challenges/java-currency-formatter/problem) | [JavaCurrencyFormatter.java](LANGUAGE%20PROFICIENCY/Java/Introduction/JavaCurrencyFormatter.java)	| Introduction | Easy | [Java Currency Formatter](https://www.hackerrank.com/challenges/java-currency-formatter/problem) | [JavaCurrencyFormatter.java](LANGUAGE%20PROFICIENCY/Java/Introduction/JavaCurrencyFormatter.java)
| Strings | Easy | [Java Strings Introduction](https://www.hackerrank.com/challenges/java-strings-introduction/problem) | [JavaStringsIntroduction.java](LANGUAGE%20PROFICIENCY/Java/Strings/JavaStringsIntroduction.java)	| Strings | Easy | [Java Strings Introduction](https://www.hackerrank.com/challenges/java-strings-introduction/problem) | [JavaStringsIntroduction.java](LANGUAGE%20PROFICIENCY/Java/Strings/JavaStringsIntroduction.java)
| Strings | Easy | [Java Substring](https://www.hackerrank.com/challenges/java-substring/problem) | [JavaSubstring.java](LANGUAGE%20PROFICIENCY/Java/Strings/JavaSubstring.java)	| Strings | Easy | [Java Substring](https://www.hackerrank.com/challenges/java-substring/problem) | [JavaSubstring.java](LANGUAGE%20PROFICIENCY/Java/Strings/JavaSubstring.java)
| Strings | Easy | [Java Substring Comparisons](https://www.hackerrank.com/challenges/java-string-compare/problem) | [JavaSubstringComparisons.java](LANGUAGE%20PROFICIENCY/Java/Strings/JavaSubstringComparisons.java)	| Strings | Easy | [Java Substring Comparisons](https://www.hackerrank.com/challenges/java-string-compare/problem) | [JavaSubstringComparisons.java](LANGUAGE%20PROFICIENCY/Java/Strings/JavaSubstringComparisons.java)
| Strings | Easy | [Java String Reverse](https://www.hackerrank.com/challenges/java-string-reverse/problem) | [JavaStringReverse.java](LANGUAGE%20PROFICIENCY/Java/Strings/JavaStringReverse.java)	| Strings | Easy | [Java String Reverse](https://www.hackerrank.com/challenges/java-string-reverse/problem) | [JavaStringReverse.java](LANGUAGE%20PROFICIENCY/Java/Strings/JavaStringReverse.java)
| Strings | Easy | [Java Anagrams](https://www.hackerrank.com/challenges/java-anagrams/problem) | [JavaAnagrams.java](LANGUAGE%20PROFICIENCY/Java/Strings/JavaAnagrams.java)	| Strings | Easy | [Java Anagrams](https://www.hackerrank.com/challenges/java-anagrams/problem) | [JavaAnagrams.java](LANGUAGE%20PROFICIENCY/Java/Strings/JavaAnagrams.java)
| Strings | Easy | [Java String Tokens](https://www.hackerrank.com/challenges/java-string-tokens/problem) | [JavaStringTokens.java](LANGUAGE%20PROFICIENCY/Java/Strings/JavaStringTokens.java)	| Strings | Easy | [Java String Tokens](https://www.hackerrank.com/challenges/java-string-tokens/problem) | [JavaStringTokens.java](LANGUAGE%20PROFICIENCY/Java/Strings/JavaStringTokens.java)
| Strings | Easy | [Pattern Syntax Checker](https://www.hackerrank.com/challenges/pattern-syntax-checker/problem) | [PatternSyntaxChecker.java](LANGUAGE%20PROFICIENCY/Java/Strings/PatternSyntaxChecker.java)	| Strings | Easy | [Pattern Syntax Checker](https://www.hackerrank.com/challenges/pattern-syntax-checker/problem) | [PatternSyntaxChecker.java](LANGUAGE%20PROFICIENCY/Java/Strings/PatternSyntaxChecker.java)
| Strings | Medium | [Java Regex](https://www.hackerrank.com/challenges/java-regex/problem) | [JavaRegex.java](LANGUAGE%20PROFICIENCY/Java/Strings/JavaRegex.java)	| Strings | Medium | [Java Regex](https://www.hackerrank.com/challenges/java-regex/problem) | [JavaRegex.java](LANGUAGE%20PROFICIENCY/Java/Strings/JavaRegex.java)
| Strings | Medium | [Java Regex 2 - Duplicate Words](https://www.hackerrank.com/challenges/duplicate-word/problem) | [JavaRegex2DuplicateWords.java](LANGUAGE%20PROFICIENCY/Java/Strings/JavaRegex2DuplicateWords.java)	| Strings | Medium | [Java Regex 2 - Duplicate Words](https://www.hackerrank.com/challenges/duplicate-word/problem) | [JavaRegex2DuplicateWords.java](LANGUAGE%20PROFICIENCY/Java/Strings/JavaRegex2DuplicateWords.java)
| Strings | Easy | [Valid Username Regular Expression](https://www.hackerrank.com/challenges/valid-username-checker/problem) | [ValidUsernameRegularExpression.java](LANGUAGE%20PROFICIENCY/Java/Strings/ValidUsernameRegularExpression.java)	| Strings | Easy | [Valid Username Regular Expression](https://www.hackerrank.com/challenges/valid-username-checker/problem) | [ValidUsernameRegularExpression.java](LANGUAGE%20PROFICIENCY/Java/Strings/ValidUsernameRegularExpression.java)
| Strings | Medium | [Tag Content Extractor](https://www.hackerrank.com/challenges/tag-content-extractor/problem) | [TagContentExtractor.java](LANGUAGE%20PROFICIENCY/Java/Strings/TagContentExtractor.java)	| Strings | Medium | [Tag Content Extractor](https://www.hackerrank.com/challenges/tag-content-extractor/problem) | [TagContentExtractor.java](LANGUAGE%20PROFICIENCY/Java/Strings/TagContentExtractor.java)
| BigNumber | Medium | [Java BigDecimal](https://www.hackerrank.com/challenges/java-bigdecimal/problem) | [JavaBigDecimal.java](LANGUAGE%20PROFICIENCY/Java/BigNumber/JavaBigDecimal.java)	| BigNumber | Medium | [Java BigDecimal](https://www.hackerrank.com/challenges/java-bigdecimal/problem) | [JavaBigDecimal.java](LANGUAGE%20PROFICIENCY/Java/BigNumber/JavaBigDecimal.java)
| BigNumber | Easy | [Java BigInteger](https://www.hackerrank.com/challenges/java-biginteger/problem) | [JavaBigInteger.java](LANGUAGE%20PROFICIENCY/Java/BigNumber/JavaBigInteger.java)	| BigNumber | Easy | [Java BigInteger](https://www.hackerrank.com/challenges/java-biginteger/problem) | [JavaBigInteger.java](LANGUAGE%20PROFICIENCY/Java/BigNumber/JavaBigInteger.java)
# Python	# Python
| Subdomain | Difficulty | Challenge | Solution |	| Subdomain | Difficulty | Challenge | Solution |
|:--:|:--:|:--:|:--:|	|:--:|:--:|:--:|:--:|
| Introduction | Easy | [Say "Hello, World!" With Python](https://www.hackerrank.com/challenges/py-hello-world/problem) | [SayHelloWorldWithPython.py](LANGUAGE%20PROFICIENCY/Python/Introduction/SayHelloWorldWithPython.py)	| Introduction | Easy | [Say "Hello, World!" With Python](https://www.hackerrank.com/challenges/py-hello-world/problem) | [SayHelloWorldWithPython.py](LANGUAGE%20PROFICIENCY/Python/Introduction/SayHelloWorldWithPython.py)
| Introduction | Easy | [Python If-Else](https://www.hackerrank.com/challenges/py-if-else/problem) | [PythonIfElse.py](LANGUAGE%20PROFICIENCY/Python/Introduction/PythonIfElse.py)	| Introduction | Easy | [Python If-Else](https://www.hackerrank.com/challenges/py-if-else/problem) | [PythonIfElse.py](LANGUAGE%20PROFICIENCY/Python/Introduction/PythonIfElse.py)
| Introduction | Easy | [Arithmetic Operators](https://www.hackerrank.com/challenges/python-arithmetic-operators/problem) | [ArithmeticOperators.py](LANGUAGE%20PROFICIENCY/Python/Introduction/ArithmeticOperators.py)	| Introduction | Easy | [Arithmetic Operators](https://www.hackerrank.com/challenges/python-arithmetic-operators/problem) | [ArithmeticOperators.py](LANGUAGE%20PROFICIENCY/Python/Introduction/ArithmeticOperators.py)
| Introduction | Easy | [Python: Division](https://www.hackerrank.com/challenges/python-division/problem) | [PythonDivision.py](LANGUAGE%20PROFICIENCY/Python/Introduction/PythonDivision.py)	| Introduction | Easy | [Python: Division](https://www.hackerrank.com/challenges/python-division/problem) | [PythonDivision.py](LANGUAGE%20PROFICIENCY/Python/Introduction/PythonDivision.py)
| Introduction | Easy | [Loops](https://www.hackerrank.com/challenges/python-loops/problem) | [Loops.py](LANGUAGE%20PROFICIENCY/Python/Introduction/Loops.py)	| Introduction | Easy | [Loops](https://www.hackerrank.com/challenges/python-loops/problem) | [Loops.py](LANGUAGE%20PROFICIENCY/Python/Introduction/Loops.py)
| Introduction | Easy | [Print Function](https://www.hackerrank.com/challenges/python-print/problem) | [PrintFunction.py](LANGUAGE%20PROFICIENCY/Python/Introduction/PrintFunction.py)	| Introduction | Easy | [Print Function](https://www.hackerrank.com/challenges/python-print/problem) | [PrintFunction.py](LANGUAGE%20PROFICIENCY/Python/Introduction/PrintFunction.py)
| Introduction | Medium | [Write a function](https://www.hackerrank.com/challenges/write-a-function/problem) | [WriteAFunction.py](Python/Introduction/WriteAFunction.py)	| Introduction | Medium | [Write a function](https://www.hackerrank.com/challenges/write-a-function/problem) | [WriteAFunction.py](Python/Introduction/WriteAFunction.py)
| Basic Data Types | Easy | [Lists](https://www.hackerrank.com/challenges/python-lists/problem) | [Lists.py](LANGUAGE%20PROFICIENCY/Python/Basic%20Data%20Types/Lists.py)	| Basic Data Types | Easy | [Lists](https://www.hackerrank.com/challenges/python-lists/problem) | [Lists.py](LANGUAGE%20PROFICIENCY/Python/Basic%20Data%20Types/Lists.py)
| Basic Data Types | Easy | [Tuples](https://www.hackerrank.com/challenges/python-tuples/problem) | [Tuples.py](LANGUAGE%20PROFICIENCY/Python/Basic%20Data%20Types/Tuples.py)	| Basic Data Types | Easy | [Tuples](https://www.hackerrank.com/challenges/python-tuples/problem) | [Tuples.py](LANGUAGE%20PROFICIENCY/Python/Basic%20Data%20Types/Tuples.py)
| Basic Data Types | Easy | [List Comprehensions](https://www.hackerrank.com/challenges/list-comprehensions/problem) | [ListComprehensions.py](LANGUAGE%20PROFICIENCY/Python/Basic%20Data%20Types/ListComprehensions.py)	| Basic Data Types | Easy | [List Comprehensions](https://www.hackerrank.com/challenges/list-comprehensions/problem) | [ListComprehensions.py](LANGUAGE%20PROFICIENCY/Python/Basic%20Data%20Types/ListComprehensions.py)
| Basic Data Types | Easy | [Find the Runner-Up Score!](https://www.hackerrank.com/challenges/find-second-maximum-number-in-a-list/problem) | [FindTheRunnerUpScore.py](LANGUAGE%20PROFICIENCY/Python/Basic%20Data%20Types/FindTheRunnerUpScore.py)	| Basic Data Types | Easy | [Find the Runner-Up Score!](https://www.hackerrank.com/challenges/find-second-maximum-number-in-a-list/problem) | [FindTheRunnerUpScore.py](LANGUAGE%20PROFICIENCY/Python/Basic%20Data%20Types/FindTheRunnerUpScore.py)
| Basic Data Types | Easy | [Nested Lists](https://www.hackerrank.com/challenges/nested-list/problem) | [NestedLists.py](LANGUAGE%20PROFICIENCY/Python/Basic%20Data%20Types/NestedLists.py)	| Basic Data Types | Easy | [Nested Lists](https://www.hackerrank.com/challenges/nested-list/problem) | [NestedLists.py](LANGUAGE%20PROFICIENCY/Python/Basic%20Data%20Types/NestedLists.py)
| Basic Data Types | Easy | [Finding the percentage](https://www.hackerrank.com/challenges/finding-the-percentage/problem) | [FindingThePercentage.py](LANGUAGE%20PROFICIENCY/Python/Basic%20Data%20Types/FindingThePercentage.py)	| Basic Data Types | Easy | [Finding the percentage](https://www.hackerrank.com/challenges/finding-the-percentage/problem) | [FindingThePercentage.py](LANGUAGE%20PROFICIENCY/Python/Basic%20Data%20Types/FindingThePercentage.py)
| Strings | Easy | [sWAP cASE](https://www.hackerrank.com/challenges/swap-case/problem) | [SwapCase.py](LANGUAGE%20PROFICIENCY/Python/Strings/SwapCase.py)	| Strings | Easy | [sWAP cASE](https://www.hackerrank.com/challenges/swap-case/problem) | [SwapCase.py](LANGUAGE%20PROFICIENCY/Python/Strings/SwapCase.py)
| Strings | Easy | [String Split and Join](https://www.hackerrank.com/challenges/python-string-split-and-join/problem) | [StringSplitAndJoin.py](LANGUAGE%20PROFICIENCY/Python/Strings/StringSplitAndJoin.py)	| Strings | Easy | [String Split and Join](https://www.hackerrank.com/challenges/python-string-split-and-join/problem) | [StringSplitAndJoin.py](LANGUAGE%20PROFICIENCY/Python/Strings/StringSplitAndJoin.py)
| Strings | Easy | [What's Your Name?](https://www.hackerrank.com/challenges/whats-your-name/problem) | [WhatsYourName.py](LANGUAGE%20PROFICIENCY/Python/Strings/WhatsYourName.py)	| Strings | Easy | [What's Your Name?](https://www.hackerrank.com/challenges/whats-your-name/problem) | [WhatsYourName.py](LANGUAGE%20PROFICIENCY/Python/Strings/WhatsYourName.py)
| Strings | Easy | [Mutations](https://www.hackerrank.com/challenges/python-mutations/problem) | [Mutations.py](LANGUAGE%20PROFICIENCY/Python/Strings/Mutations.py)	| Strings | Easy | [Mutations](https://www.hackerrank.com/challenges/python-mutations/problem) | [Mutations.py](LANGUAGE%20PROFICIENCY/Python/Strings/Mutations.py)
| Strings | Easy | [Find a string](https://www.hackerrank.com/challenges/find-a-string/problem) | [FindAString.py](LANGUAGE%20PROFICIENCY/Python/Strings/FindAString.py)	| Strings | Easy | [Find a string](https://www.hackerrank.com/challenges/find-a-string/problem) | [FindAString.py](LANGUAGE%20PROFICIENCY/Python/Strings/FindAString.py)
| Strings | Easy | [String Validators](https://www.hackerrank.com/challenges/string-validators/problem) | [StringValidators.py](LANGUAGE%20PROFICIENCY/Python/Strings/StringValidators.py)	| Strings | Easy | [String Validators](https://www.hackerrank.com/challenges/string-validators/problem) | [StringValidators.py](LANGUAGE%20PROFICIENCY/Python/Strings/StringValidators.py)
| Strings | Easy | [Text Alignment](https://www.hackerrank.com/challenges/text-alignment/problem) | [TextAlignment.py](LANGUAGE%20PROFICIENCY/Python/Strings/TextAlignment.py)	| Strings | Easy | [Text Alignment](https://www.hackerrank.com/challenges/text-alignment/problem) | [TextAlignment.py](LANGUAGE%20PROFICIENCY/Python/Strings/TextAlignment.py)
| Strings | Easy | [Text Wrap](https://www.hackerrank.com/challenges/text-wrap/problem) | [TextWrap.py](LANGUAGE%20PROFICIENCY/Python/Strings/TextWrap.py)	| Strings | Easy | [Text Wrap](https://www.hackerrank.com/challenges/text-wrap/problem) | [TextWrap.py](LANGUAGE%20PROFICIENCY/Python/Strings/TextWrap.py)
| Strings | Easy | [Designer Door Mat](https://www.hackerrank.com/challenges/designer-door-mat/problem) | [DesignerDoorMat.py](LANGUAGE%20PROFICIENCY/Python/Strings/DesignerDoorMat.py)	| Strings | Easy | [Designer Door Mat](https://www.hackerrank.com/challenges/designer-door-mat/problem) | [DesignerDoorMat.py](LANGUAGE%20PROFICIENCY/Python/Strings/DesignerDoorMat.py)
| Strings | Easy | [String Formatting](https://www.hackerrank.com/challenges/python-string-formatting/problem) | [StringFormatting.py](LANGUAGE%20PROFICIENCY/Python/Strings/StringFormatting.py)	| Strings | Easy | [String Formatting](https://www.hackerrank.com/challenges/python-string-formatting/problem) | [StringFormatting.py](LANGUAGE%20PROFICIENCY/Python/Strings/StringFormatting.py)
| Strings | Easy | [Alphabet Rangoli](https://www.hackerrank.com/challenges/alphabet-rangoli/problem) | [AlphabetRangoli.py](LANGUAGE%20PROFICIENCY/Python/Strings/AlphabetRangoli.py)	| Strings | Easy | [Alphabet Rangoli](https://www.hackerrank.com/challenges/alphabet-rangoli/problem) | [AlphabetRangoli.py](LANGUAGE%20PROFICIENCY/Python/Strings/AlphabetRangoli.py)
| Strings | Easy | [Capitalize!](https://www.hackerrank.com/challenges/capitalize/problem) | [Capitalize.py](LANGUAGE%20PROFICIENCY/Python/Strings/Capitalize.py)	| Strings | Easy | [Capitalize!](https://www.hackerrank.com/challenges/capitalize/problem) | [Capitalize.py](LANGUAGE%20PROFICIENCY/Python/Strings/Capitalize.py)
| Strings | Medium | [The Minion Game](https://www.hackerrank.com/challenges/the-minion-game/problem) | [TheMinionGame.py](LANGUAGE%20PROFICIENCY/Python/Strings/TheMinionGame.py)	| Strings | Medium | [The Minion Game](https://www.hackerrank.com/challenges/the-minion-game/problem) | [TheMinionGame.py](LANGUAGE%20PROFICIENCY/Python/Strings/TheMinionGame.py)
| Strings | Medium | [Merge the Tools!](https://www.hackerrank.com/challenges/merge-the-tools/problem) | [MergeTheTools.py](LANGUAGE%20PROFICIENCY/Python/Strings/MergeTheTools.py)	| Strings | Medium | [Merge the Tools!](https://www.hackerrank.com/challenges/merge-the-tools/problem) | [MergeTheTools.py](LANGUAGE%20PROFICIENCY/Python/Strings/MergeTheTools.py)
| Sets | Easy | [Introduction to Sets](https://www.hackerrank.com/challenges/py-introduction-to-sets/problem) | [IntroductionToSets.py](LANGUAGE%20PROFICIENCY/Python/Sets/IntroductionToSets.py)	| Sets | Easy | [Introduction to Sets](https://www.hackerrank.com/challenges/py-introduction-to-sets/problem) | [IntroductionToSets.py](LANGUAGE%20PROFICIENCY/Python/Sets/IntroductionToSets.py)
| Sets | Medium | [No Idea!](https://www.hackerrank.com/challenges/no-idea/problem) | [NoIdea.py](LANGUAGE%20PROFICIENCY/Python/Sets/NoIdea.py)	| Sets | Medium | [No Idea!](https://www.hackerrank.com/challenges/no-idea/problem) | [NoIdea.py](LANGUAGE%20PROFICIENCY/Python/Sets/NoIdea.py)
# Shell	# Shell
| Subdomain | Difficulty | Challenge | Solution |	| Subdomain | Difficulty | Challenge | Solution |
|:--:|:--:|:--:|:--:|	|:--:|:--:|:--:|:--:|
| Bash | Easy | [Let's Echo](https://www.hackerrank.com/challenges/bash-tutorials-lets-echo/problem) | [LetsEcho.sh](LANGUAGE%20PROFICIENCY/Shell/Bash/LetsEcho.sh)	| Bash | Easy | [Let's Echo](https://www.hackerrank.com/challenges/bash-tutorials-lets-echo/problem) | [LetsEcho.sh](LANGUAGE%20PROFICIENCY/Shell/Bash/LetsEcho.sh)
| Bash | Easy | [A Personalized Echo](https://www.hackerrank.com/challenges/bash-tutorials---a-personalized-echo/problem) | [APersonalizedEcho.sh](LANGUAGE%20PROFICIENCY/Shell/Bash/APersonalizedEcho.sh)	| Bash | Easy | [A Personalized Echo](https://www.hackerrank.com/challenges/bash-tutorials---a-personalized-echo/problem) | [APersonalizedEcho.sh](LANGUAGE%20PROFICIENCY/Shell/Bash/APersonalizedEcho.sh)
| Bash | Easy | [Looping and Skipping](https://www.hackerrank.com/challenges/bash-tutorials---looping-and-skipping/problem) | [LoopingAndSkipping.sh](LANGUAGE%20PROFICIENCY/Shell/Bash/LoopingAndSkipping.sh)	| Bash | Easy | [Looping and Skipping](https://www.hackerrank.com/challenges/bash-tutorials---looping-and-skipping/problem) | [LoopingAndSkipping.sh](LANGUAGE%20PROFICIENCY/Shell/Bash/LoopingAndSkipping.sh)
| Bash | Easy | [Looping with Numbers](https://www.hackerrank.com/challenges/bash-tutorials---looping-with-numbers/problem) | [LoopingWithNumbers.sh](LANGUAGE%20PROFICIENCY/Shell/Bash/LoopingWithNumbers.sh)	| Bash | Easy | [Looping with Numbers](https://www.hackerrank.com/challenges/bash-tutorials---looping-with-numbers/problem) | [LoopingWithNumbers.sh](LANGUAGE%20PROFICIENCY/Shell/Bash/LoopingWithNumbers.sh)
| Bash | Easy | [The World of Numbers](https://www.hackerrank.com/challenges/bash-tutorials---the-world-of-numbers/problem) | [TheWorldOfNumbers.sh](LANGUAGE%20PROFICIENCY/Shell/Bash/TheWorldOfNumbers.sh)	| Bash | Easy | [The World of Numbers](https://www.hackerrank.com/challenges/bash-tutorials---the-world-of-numbers/problem) | [TheWorldOfNumbers.sh](LANGUAGE%20PROFICIENCY/Shell/Bash/TheWorldOfNumbers.sh)
| Bash | Easy | [Comparing Numbers](https://www.hackerrank.com/challenges/bash-tutorials---comparing-numbers/problem) | [ComparingNumbers.sh](LANGUAGE%20PROFICIENCY/Shell/Bash/ComparingNumbers.sh)	| Bash | Easy | [Comparing Numbers](https://www.hackerrank.com/challenges/bash-tutorials---comparing-numbers/problem) | [ComparingNumbers.sh](LANGUAGE%20PROFICIENCY/Shell/Bash/ComparingNumbers.sh)
| Bash | Easy | [Getting started with conditionals](https://www.hackerrank.com/challenges/bash-tutorials---getting-started-with-conditionals/problem) | [ComparingNumbers.sh](LANGUAGE%20PROFICIENCY/Shell/Bash/ComparingNumbers.sh)	| Bash | Easy | [Getting started with conditionals](https://www.hackerrank.com/challenges/bash-tutorials---getting-started-with-conditionals/problem) | [ComparingNumbers.sh](LANGUAGE%20PROFICIENCY/Shell/Bash/ComparingNumbers.sh)
| Bash | Easy | [More on Conditionals](https://www.hackerrank.com/challenges/bash-tutorials---more-on-conditionals/problem) | [MoreOnConditionals.sh](LANGUAGE%20PROFICIENCY/Shell/Bash/MoreOnConditionals.sh)	| Bash | Easy | [More on Conditionals](https://www.hackerrank.com/challenges/bash-tutorials---more-on-conditionals/problem) | [MoreOnConditionals.sh](LANGUAGE%20PROFICIENCY/Shell/Bash/MoreOnConditionals.sh)
| Bash | Medium | [Arithmetic Operations](https://www.hackerrank.com/challenges/bash-tutorials---arithmetic-operations/problem) | [ArithmeticOperations.sh](LANGUAGE%20PROFICIENCY/Shell/Bash/ArithmeticOperations.sh)	| Bash | Medium | [Arithmetic Operations](https://www.hackerrank.com/challenges/bash-tutorials---arithmetic-operations/problem) | [ArithmeticOperations.sh](LANGUAGE%20PROFICIENCY/Shell/Bash/ArithmeticOperations.sh)
| Bash | Medium | [Compute the Average](https://www.hackerrank.com/challenges/bash-tutorials---compute-the-average/problem) | [ComputeTheAverage.sh](LANGUAGE%20PROFICIENCY/Shell/Bash/ComputeTheAverage.sh)	| Bash | Medium | [Compute the Average](https://www.hackerrank.com/challenges/bash-tutorials---compute-the-average/problem) | [ComputeTheAverage.sh](LANGUAGE%20PROFICIENCY/Shell/Bash/ComputeTheAverage.sh)
| Bash | Hard | [Functions and Fractals - Recursive Trees - Bash!](https://www.hackerrank.com/challenges/fractal-trees-all/problem) | [FunctionsAndFractalsRecursiveTreesBash.sh](LANGUAGE%20PROFICIENCY/Shell/Bash/FunctionsAndFractalsRecursiveTreesBash.sh)	| Bash | Hard | [Functions and Fractals - Recursive Trees - Bash!](https://www.hackerrank.com/challenges/fractal-trees-all/problem) | [FunctionsAndFractalsRecursiveTreesBash.sh](LANGUAGE%20PROFICIENCY/Shell/Bash/FunctionsAndFractalsRecursiveTreesBash.sh)
| Text Processing | Easy | [Cut #1](https://www.hackerrank.com/challenges/text-processing-cut-1/problem) | [Cut#1.sh](LANGUAGE%20PROFICIENCY/Shell/Text%20Processing/Cut%231.sh)	| Text Processing | Easy | [Cut #1](https://www.hackerrank.com/challenges/text-processing-cut-1/problem) | [Cut#1.sh](LANGUAGE%20PROFICIENCY/Shell/Text%20Processing/Cut%231.sh)
| Text Processing | Easy | [Cut #2](https://www.hackerrank.com/challenges/text-processing-cut-2/problem) | [Cut#2.sh](LANGUAGE%20PROFICIENCY/Shell/Text%20Processing/Cut%232.sh)	| Text Processing | Easy | [Cut #2](https://www.hackerrank.com/challenges/text-processing-cut-2/problem) | [Cut#2.sh](LANGUAGE%20PROFICIENCY/Shell/Text%20Processing/Cut%232.sh)
| Text Processing | Easy | [Cut #3](https://www.hackerrank.com/challenges/text-processing-cut-3/problem) | [Cut#3.sh](LANGUAGE%20PROFICIENCY/Shell/Text%20Processing/Cut%233.sh)	| Text Processing | Easy | [Cut #3](https://www.hackerrank.com/challenges/text-processing-cut-3/problem) | [Cut#3.sh](LANGUAGE%20PROFICIENCY/Shell/Text%20Processing/Cut%233.sh)
| Text Processing | Easy | [Cut #4](https://www.hackerrank.com/challenges/text-processing-cut-4/problem) | [Cut#4.sh](LANGUAGE%20PROFICIENCY/Shell/Text%20Processing/Cut#4.sh)	| Text Processing | Easy | [Cut #4](https://www.hackerrank.com/challenges/text-processing-cut-4/problem) | [Cut#4.sh](LANGUAGE%20PROFICIENCY/Shell/Text%20Processing/Cut#4.sh)
| Text Processing | Easy | [Cut #5](https://www.hackerrank.com/challenges/text-processing-cut-5/problem) | [Cut#5.sh](LANGUAGE%20PROFICIENCY/Shell/Text%20Processing/Cut#5.sh)	| Text Processing | Easy | [Cut #5](https://www.hackerrank.com/challenges/text-processing-cut-5/problem) | [Cut#5.sh](LANGUAGE%20PROFICIENCY/Shell/Text%20Processing/Cut#5.sh)
| Text Processing | Easy | [Cut #6](https://www.hackerrank.com/challenges/text-processing-cut-6/problem) | [Cut#6.sh](LANGUAGE%20PROFICIENCY/Shell/Text%20Processing/Cut#6.sh)	| Text Processing | Easy | [Cut #6](https://www.hackerrank.com/challenges/text-processing-cut-6/problem) | [Cut#6.sh](LANGUAGE%20PROFICIENCY/Shell/Text%20Processing/Cut#6.sh)
| Text Processing | Easy | [Cut #7](https://www.hackerrank.com/challenges/text-processing-cut-7/problem) | [Cut#7.sh](LANGUAGE%20PROFICIENCY/Shell/Text%20Processing/Cut#7.sh)	| Text Processing | Easy | [Cut #7](https://www.hackerrank.com/challenges/text-processing-cut-7/problem) | [Cut#7.sh](LANGUAGE%20PROFICIENCY/Shell/Text%20Processing/Cut#7.sh)
| Text Processing | Easy | [Cut #8](https://www.hackerrank.com/challenges/text-processing-cut-8/problem) | [Cut#8.sh](LANGUAGE%20PROFICIENCY/Shell/Text%20Processing/Cut#8.sh)	| Text Processing | Easy | [Cut #8](https://www.hackerrank.com/challenges/text-processing-cut-8/problem) | [Cut#8.sh](LANGUAGE%20PROFICIENCY/Shell/Text%20Processing/Cut#8.sh)
| Text Processing | Easy | [Cut #9](https://www.hackerrank.com/challenges/text-processing-cut-9/problem) | [Cut#9.sh](LANGUAGE%20PROFICIENCY/Shell/Text%20Processing/Cut#9.sh)	| Text Processing | Easy | [Cut #9](https://www.hackerrank.com/challenges/text-processing-cut-9/problem) | [Cut#9.sh](LANGUAGE%20PROFICIENCY/Shell/Text%20Processing/Cut#9.sh)
| Text Processing | Easy | [Head of a Text File #1](https://www.hackerrank.com/challenges/text-processing-head-1/problem) | [HeadOfATextFile#1.sh](LANGUAGE%20PROFICIENCY/Shell/Text%20Processing/HeadOfATextFile#1.sh)	| Text Processing | Easy | [Head of a Text File #1](https://www.hackerrank.com/challenges/text-processing-head-1/problem) | [HeadOfATextFile#1.sh](LANGUAGE%20PROFICIENCY/Shell/Text%20Processing/HeadOfATextFile#1.sh)
| Text Processing | Easy | [Head of a Text File #2](https://www.hackerrank.com/challenges/text-processing-head-2/problem) | [HeadOfATextFile#2.sh](LANGUAGE%20PROFICIENCY/Shell/Text%20Processing/HeadOfATextFile#2.sh)	| Text Processing | Easy | [Head of a Text File #2](https://www.hackerrank.com/challenges/text-processing-head-2/problem) | [HeadOfATextFile#2.sh](LANGUAGE%20PROFICIENCY/Shell/Text%20Processing/HeadOfATextFile#2.sh)
| Text Processing | Easy | [Tail of a Text File #1](https://www.hackerrank.com/challenges/text-processing-tail-1/problem) | [TailOfATextFile#1.sh](LANGUAGE%20PROFICIENCY/Shell/Text%20Processing/TailOfATextFile#1.sh)	| Text Processing | Easy | [Tail of a Text File #1](https://www.hackerrank.com/challenges/text-processing-tail-1/problem) | [TailOfATextFile#1.sh](LANGUAGE%20PROFICIENCY/Shell/Text%20Processing/TailOfATextFile#1.sh)
| Text Processing | Easy | [Tail of a Text File #2](https://www.hackerrank.com/challenges/text-processing-tail-2/problem) | [TailOfATextFile#2.sh](LANGUAGE%20PROFICIENCY/Shell/Text%20Processing/TailOfATextFile#2.sh)	| Text Processing | Easy | [Tail of a Text File #2](https://www.hackerrank.com/challenges/text-processing-tail-2/problem) | [TailOfATextFile#2.sh](LANGUAGE%20PROFICIENCY/Shell/Text%20Processing/TailOfATextFile#2.sh)
| Text Processing | Easy | [Middle of a Text File](https://www.hackerrank.com/challenges/text-processing-in-linux---the-middle-of-a-text-file/problem) | [MiddleOfATextFile.sh](LANGUAGE%20PROFICIENCY/Shell/Text%20Processing/MiddleOfATextFile.sh)	| Text Processing | Easy | [Middle of a Text File](https://www.hackerrank.com/challenges/text-processing-in-linux---the-middle-of-a-text-file/problem) | [MiddleOfATextFile.sh](LANGUAGE%20PROFICIENCY/Shell/Text%20Processing/MiddleOfATextFile.sh)
| Text Processing | Easy | ['Tr' Command #1](https://www.hackerrank.com/challenges/text-processing-tr-1/problem) | [TrCommand#1.sh](LANGUAGE%20PROFICIENCY/Shell/Text%20Processing/TrCommand#1.sh)	| Text Processing | Easy | ['Tr' Command #1](https://www.hackerrank.com/challenges/text-processing-tr-1/problem) | [TrCommand#1.sh](LANGUAGE%20PROFICIENCY/Shell/Text%20Processing/TrCommand#1.sh)
| Text Processing | Easy | ['Tr' Command #2](https://www.hackerrank.com/challenges/text-processing-sort-2/problem) | [TrCommand#2.sh](LANGUAGE%20PROFICIENCY/Shell/Text%20Processing/TrCommand#2.sh)	| Text Processing | Easy | ['Tr' Command #2](https://www.hackerrank.com/challenges/text-processing-sort-2/problem) | [TrCommand#2.sh](LANGUAGE%20PROFICIENCY/Shell/Text%20Processing/TrCommand#2.sh)
| Text Processing | Easy | ['Tr' Command #3](https://www.hackerrank.com/challenges/text-processing-tr-3/problem) | [TrCommand#3.sh](LANGUAGE%20PROFICIENCY/Shell/Text%20Processing/TrCommand#3.sh)	| Text Processing | Easy | ['Tr' Command #3](https://www.hackerrank.com/challenges/text-processing-tr-3/problem) | [TrCommand#3.sh](LANGUAGE%20PROFICIENCY/Shell/Text%20Processing/TrCommand#3.sh)
| Text Processing | Easy | [Sort Command #1](https://www.hackerrank.com/challenges/text-processing-sort-1/problem) | [SortCommand#1.sh](LANGUAGE%20PROFICIENCY/Shell/Text%20Processing/SortCommand#1.sh)	| Text Processing | Easy | [Sort Command #1](https://www.hackerrank.com/challenges/text-processing-sort-1/problem) | [SortCommand#1.sh](LANGUAGE%20PROFICIENCY/Shell/Text%20Processing/SortCommand#1.sh)
| Text Processing | Easy | [Sort Command #2](https://www.hackerrank.com/challenges/text-processing-sort-2/problem) | [SortCommand#2.sh](LANGUAGE%20PROFICIENCY/Shell/Text%20Processing/SortCommand#2.sh)	| Text Processing | Easy | [Sort Command #2](https://www.hackerrank.com/challenges/text-processing-sort-2/problem) | [SortCommand#2.sh](LANGUAGE%20PROFICIENCY/Shell/Text%20Processing/SortCommand#2.sh)
| Text Processing | Easy | [Sort Command #3](https://www.hackerrank.com/challenges/text-processing-sort-3/problem) | [SortCommand#3.sh](LANGUAGE%20PROFICIENCY/Shell/Text%20Processing/SortCommand#3.sh)	| Text Processing | Easy | [Sort Command #3](https://www.hackerrank.com/challenges/text-processing-sort-3/problem) | [SortCommand#3.sh](LANGUAGE%20PROFICIENCY/Shell/Text%20Processing/SortCommand#3.sh)
| Text Processing | Easy | [Sort Command #4](https://www.hackerrank.com/challenges/text-processing-sort-4/problem) | [SortCommand#4.sh](LANGUAGE%20PROFICIENCY/Shell/Text%20Processing/SortCommand#4.sh)	| Text Processing | Easy | [Sort Command #4](https://www.hackerrank.com/challenges/text-processing-sort-4/problem) | [SortCommand#4.sh](LANGUAGE%20PROFICIENCY/Shell/Text%20Processing/SortCommand#4.sh)
| Text Processing | Easy | [Sort Command #5](https://www.hackerrank.com/challenges/text-processing-sort-5/problem) | [SortCommand#5.sh](LANGUAGE%20PROFICIENCY/Shell/Text%20Processing/SortCommand#5.sh)	| Text Processing | Easy | [Sort Command #5](https://www.hackerrank.com/challenges/text-processing-sort-5/problem) | [SortCommand#5.sh](LANGUAGE%20PROFICIENCY/Shell/Text%20Processing/SortCommand#5.sh)
| Text Processing | Easy | [Sort Command #6](https://www.hackerrank.com/challenges/text-processing-sort-6/problem) | [SortCommand#6.sh](LANGUAGE%20PROFICIENCY/Shell/Text%20Processing/SortCommand#6.sh)	| Text Processing | Easy | [Sort Command #6](https://www.hackerrank.com/challenges/text-processing-sort-6/problem) | [SortCommand#6.sh](LANGUAGE%20PROFICIENCY/Shell/Text%20Processing/SortCommand#6.sh)
| Text Processing | Easy | [Sort Command #7](https://www.hackerrank.com/challenges/text-processing-sort-7/problem) | [SortCommand#7.sh](LANGUAGE%20PROFICIENCY/Shell/Text%20Processing/SortCommand#7.sh)	| Text Processing | Easy | [Sort Command #7](https://www.hackerrank.com/challenges/text-processing-sort-7/problem) | [SortCommand#7.sh](LANGUAGE%20PROFICIENCY/Shell/Text%20Processing/SortCommand#7.sh)
| Text Processing | Easy | ['Uniq' Command #1](https://www.hackerrank.com/challenges/text-processing-in-linux-the-uniq-command-1/problem) | [UniqCommand#1.sh](LANGUAGE%20PROFICIENCY/Shell/Text%20Processing/UniqCommand#1.sh)	| Text Processing | Easy | ['Uniq' Command #1](https://www.hackerrank.com/challenges/text-processing-in-linux-the-uniq-command-1/problem) | [UniqCommand#1.sh](LANGUAGE%20PROFICIENCY/Shell/Text%20Processing/UniqCommand#1.sh)
| Text Processing | Easy | ['Uniq' Command #2](https://www.hackerrank.com/challenges/text-processing-in-linux-the-uniq-command-2/problem) | [UniqCommand#2.sh](LANGUAGE%20PROFICIENCY/Shell/Text%20Processing/UniqCommand#2.sh)	| Text Processing | Easy | ['Uniq' Command #2](https://www.hackerrank.com/challenges/text-processing-in-linux-the-uniq-command-2/problem) | [UniqCommand#2.sh](LANGUAGE%20PROFICIENCY/Shell/Text%20Processing/UniqCommand#2.sh)
| Text Processing | Easy | ['Uniq' Command #3](https://www.hackerrank.com/challenges/text-processing-in-linux-the-uniq-command-3/problem) | [UniqCommand#3.sh](LANGUAGE%20PROFICIENCY/Shell/Text%20Processing/UniqCommand#3.sh)	| Text Processing | Easy | ['Uniq' Command #3](https://www.hackerrank.com/challenges/text-processing-in-linux-the-uniq-command-3/problem) | [UniqCommand#3.sh](LANGUAGE%20PROFICIENCY/Shell/Text%20Processing/UniqCommand#3.sh)
| Text Processing | Easy | ['Uniq' Command #4](https://www.hackerrank.com/challenges/text-processing-in-linux-the-uniq-command-4/problem) | [UniqCommand#4.sh](LANGUAGE%20PROFICIENCY/Shell/Text%20Processing/UniqCommand#4.sh)	| Text Processing | Easy | ['Uniq' Command #4](https://www.hackerrank.com/challenges/text-processing-in-linux-the-uniq-command-4/problem) | [UniqCommand#4.sh](LANGUAGE%20PROFICIENCY/Shell/Text%20Processing/UniqCommand#4.sh)
| Text Processing | Medium | [Paste - 1](https://www.hackerrank.com/challenges/paste-1/problem) | [Paste1.sh](LANGUAGE%20PROFICIENCY/Shell/Text%20Processing/Paste1.sh)	| Text Processing | Medium | [Paste - 1](https://www.hackerrank.com/challenges/paste-1/problem) | [Paste1.sh](LANGUAGE%20PROFICIENCY/Shell/Text%20Processing/Paste1.sh)
| Text Processing | Medium | [Paste - 2](https://www.hackerrank.com/challenges/paste-2/problem) | [Paste2.sh](LANGUAGE%20PROFICIENCY/Shell/Text%20Processing/Paste2.sh)	| Text Processing | Medium | [Paste - 2](https://www.hackerrank.com/challenges/paste-2/problem) | [Paste2.sh](LANGUAGE%20PROFICIENCY/Shell/Text%20Processing/Paste2.sh)
| Text Processing | Medium | [Paste - 3](https://www.hackerrank.com/challenges/paste-3/problem) | [Paste3.sh](LANGUAGE%20PROFICIENCY/Shell/Text%20Processing/Paste3.sh)	| Text Processing | Medium | [Paste - 3](https://www.hackerrank.com/challenges/paste-3/problem) | [Paste3.sh](LANGUAGE%20PROFICIENCY/Shell/Text%20Processing/Paste3.sh)
| Text Processing | Medium | [Paste - 4](https://www.hackerrank.com/challenges/paste-4/problem) | [Paste4.sh](LANGUAGE%20PROFICIENCY/Shell/Text%20Processing/Paste4.sh)	| Text Processing | Medium | [Paste - 4](https://www.hackerrank.com/challenges/paste-4/problem) | [Paste4.sh](LANGUAGE%20PROFICIENCY/Shell/Text%20Processing/Paste4.sh)
| Arrays in Bash | Easy | [Read in an Array](https://www.hackerrank.com/challenges/bash-tutorials-read-in-an-array/problem) | [ReadInAnArray.sh](LANGUAGE%20PROFICIENCY/Shell/Arrays%20in%20%20Bash/ReadInAnArray.sh)	| Arrays in Bash | Easy | [Read in an Array](https://www.hackerrank.com/challenges/bash-tutorials-read-in-an-array/problem) | [ReadInAnArray.sh](LANGUAGE%20PROFICIENCY/Shell/Arrays%20in%20%20Bash/ReadInAnArray.sh)
| Arrays in Bash | Easy | [Slice an Array](https://www.hackerrank.com/challenges/bash-tutorials-slice-an-array/problem) | [SliceAnArray.sh](LANGUAGE%20PROFICIENCY/Shell/Arrays%20in%20%20Bash/SliceAnArray.sh)	| Arrays in Bash | Easy | [Slice an Array](https://www.hackerrank.com/challenges/bash-tutorials-slice-an-array/problem) | [SliceAnArray.sh](LANGUAGE%20PROFICIENCY/Shell/Arrays%20in%20%20Bash/SliceAnArray.sh)
| Arrays in Bash | Medium | [Filter an Array with Patterns](https://www.hackerrank.com/challenges/bash-tutorials-filter-an-array-with-patterns/problem) | [FilterAnArrayWithPatterns.sh](LANGUAGE%20PROFICIENCY/Shell/Arrays%20in%20%20Bash/FilterAnArrayWithPatterns.sh)	| Arrays in Bash | Medium | [Filter an Array with Patterns](https://www.hackerrank.com/challenges/bash-tutorials-filter-an-array-with-patterns/problem) | [FilterAnArrayWithPatterns.sh](LANGUAGE%20PROFICIENCY/Shell/Arrays%20in%20%20Bash/FilterAnArrayWithPatterns.sh)
| Arrays in Bash | Easy | [Concatenate an array with itself](https://www.hackerrank.com/challenges/bash-tutorials-concatenate-an-array-with-itself/problem) | [ConcatenateAnArrayWithItself.sh](LANGUAGE%20PROFICIENCY/Shell/Arrays%20in%20%20Bash/ConcatenateAnArrayWithItself.sh)	| Arrays in Bash | Easy | [Concatenate an array with itself](https://www.hackerrank.com/challenges/bash-tutorials-concatenate-an-array-with-itself/problem) | [ConcatenateAnArrayWithItself.sh](LANGUAGE%20PROFICIENCY/Shell/Arrays%20in%20%20Bash/ConcatenateAnArrayWithItself.sh)
| Arrays in Bash | Easy | [Display an element of an array](https://www.hackerrank.com/challenges/bash-tutorials-display-the-third-element-of-an-array/problem) | [DisplayAnElementOfAnArray.sh](LANGUAGE%20PROFICIENCY/Shell/Arrays%20in%20%20Bash/DisplayAnElementOfAnArray.sh)	| Arrays in Bash | Easy | [Display an element of an array](https://www.hackerrank.com/challenges/bash-tutorials-display-the-third-element-of-an-array/problem) | [DisplayAnElementOfAnArray.sh](LANGUAGE%20PROFICIENCY/Shell/Arrays%20in%20%20Bash/DisplayAnElementOfAnArray.sh)
| Arrays in Bash | Easy | [Count the number of elements in an Array](https://www.hackerrank.com/challenges/bash-tutorials-count-the-number-of-elements-in-an-array/problem) | [CountTheNumberOfElementsInAnArray.sh](LANGUAGE%20PROFICIENCY/Shell/Arrays%20in%20%20Bash/CountTheNumberOfElementsInAnArray.sh)	| Arrays in Bash | Easy | [Count the number of elements in an Array](https://www.hackerrank.com/challenges/bash-tutorials-count-the-number-of-elements-in-an-array/problem) | [CountTheNumberOfElementsInAnArray.sh](LANGUAGE%20PROFICIENCY/Shell/Arrays%20in%20%20Bash/CountTheNumberOfElementsInAnArray.sh)
| Arrays in Bash | Medium | [Remove the First Capital Letter from Each Element](https://www.hackerrank.com/challenges/bash-tutorials-remove-the-first-capital-letter-from-each-array-element/problem) | [RemoveTheFirstCapitalLetterFromEachElement.sh](LANGUAGE%20PROFICIENCY/Shell/Arrays%20in%20%20Bash/RemoveTheFirstCapitalLetterFromEachElement.sh)	| Arrays in Bash | Medium | [Remove the First Capital Letter from Each Element](https://www.hackerrank.com/challenges/bash-tutorials-remove-the-first-capital-letter-from-each-array-element/problem) | [RemoveTheFirstCapitalLetterFromEachElement.sh](LANGUAGE%20PROFICIENCY/Shell/Arrays%20in%20%20Bash/RemoveTheFirstCapitalLetterFromEachElement.sh)
| Arrays in Bash | Hard | [Lonely Integer - Bash!](https://www.hackerrank.com/challenges/lonely-integer-2/problem) | [LonelyIntegerBash.sh](LANGUAGE%20PROFICIENCY/Shell/Arrays%20in%20%20Bash/LonelyIntegerBash.sh)	| Arrays in Bash | Hard | [Lonely Integer - Bash!](https://www.hackerrank.com/challenges/lonely-integer-2/problem) | [LonelyIntegerBash.sh](LANGUAGE%20PROFICIENCY/Shell/Arrays%20in%20%20Bash/LonelyIntegerBash.sh)
| Grep Sed Awk | Easy | ['Grep' - A](https://www.hackerrank.com/challenges/text-processing-in-linux-the-grep-command-4/problem) | [GrepA.sh](LANGUAGE%20PROFICIENCY/Shell/Grep%20Sed%20Awk/GrepA.sh)	| Grep Sed Awk | Easy | ['Grep' - A](https://www.hackerrank.com/challenges/text-processing-in-linux-the-grep-command-4/problem) | [GrepA.sh](LANGUAGE%20PROFICIENCY/Shell/Grep%20Sed%20Awk/GrepA.sh)
| Grep Sed Awk | Easy | ['Grep' - B](https://www.hackerrank.com/challenges/text-processing-in-linux-the-grep-command-5/problem) | [GrepB.sh](LANGUAGE%20PROFICIENCY/Shell/Grep%20Sed%20Awk/GrepB.sh)	| Grep Sed Awk | Easy | ['Grep' - B](https://www.hackerrank.com/challenges/text-processing-in-linux-the-grep-command-5/problem) | [GrepB.sh](LANGUAGE%20PROFICIENCY/Shell/Grep%20Sed%20Awk/GrepB.sh)
| Grep Sed Awk | Medium | ['Grep' #1](https://www.hackerrank.com/challenges/text-processing-in-linux-the-grep-command-1/problem) | [Grep#1.sh](LANGUAGE%20PROFICIENCY/Shell/Grep%20Sed%20Awk/Grep#1.sh)	| Grep Sed Awk | Medium | ['Grep' #1](https://www.hackerrank.com/challenges/text-processing-in-linux-the-grep-command-1/problem) | [Grep#1.sh](LANGUAGE%20PROFICIENCY/Shell/Grep%20Sed%20Awk/Grep#1.sh)
| Grep Sed Awk | Medium | ['Grep' #2](https://www.hackerrank.com/challenges/text-processing-in-linux-the-grep-command-2/problem) | [Grep#2.sh](LANGUAGE%20PROFICIENCY/Shell/Grep%20Sed%20Awk/Grep#2.sh)	| Grep Sed Awk | Medium | ['Grep' #2](https://www.hackerrank.com/challenges/text-processing-in-linux-the-grep-command-2/problem) | [Grep#2.sh](LANGUAGE%20PROFICIENCY/Shell/Grep%20Sed%20Awk/Grep#2.sh)
| Grep Sed Awk | Medium | ['Grep' #3](https://www.hackerrank.com/challenges/text-processing-in-linux-the-grep-command-3/problem) | [Grep#3.sh](LANGUAGE%20PROFICIENCY/Shell/Grep%20Sed%20Awk/Grep#3.sh)	| Grep Sed Awk | Medium | ['Grep' #3](https://www.hackerrank.com/challenges/text-processing-in-linux-the-grep-command-3/problem) | [Grep#3.sh](LANGUAGE%20PROFICIENCY/Shell/Grep%20Sed%20Awk/Grep#3.sh)
