#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<assert.h>
#define MAX_CHARACTERS 1005
#define MAX_PARAGRAPHS 5
char* kth_word_in_mth_sentence_of_nth_paragraph(char**** document, int k, int m, int n) {
    return document[n - 1][m - 1][k - 1];
}

char** kth_sentence_in_mth_paragraph(char**** document, int k, int m) {
    return document[m - 1][k - 1];
}

char*** kth_paragraph(char**** document, int k) {
    return document[k - 1];
}

// Parses text into a 4-D structure [paragraph][sentence][word]
char**** get_document(char* text) {
    char**** doc = NULL;
    int p_count = 0;
    char* text_copy = strdup(text);
    char* p_saveptr;
    char* p_token = strtok_r(text_copy, "\n", &p_saveptr);
    
    while (p_token != NULL) {
        doc = realloc(doc, ++p_count * sizeof(char***));
        char* p_copy = strdup(p_token);
        int s_count = 0;
        char*** current_paragraph = NULL;
        char* s_saveptr;
        char* s_token = strtok_r(p_copy, ".", &s_saveptr);
        
        while (s_token != NULL) {
            current_paragraph = realloc(current_paragraph, ++s_count * sizeof(char**));
            char* s_copy = strdup(s_token);
            int w_count = 0;
            char** current_sentence = NULL;
            char* w_saveptr;
            char* w_token = strtok_r(s_copy, " ", &w_saveptr);
            
            while (w_token != NULL) {
                current_sentence = realloc(current_sentence, ++w_count * sizeof(char*));
                current_sentence[w_count - 1] = strdup(w_token);
                w_token = strtok_r(NULL, " ", &w_saveptr);
            }
            current_paragraph[s_count - 1] = current_sentence;
            free(s_copy);
            s_token = strtok_r(NULL, ".", &s_saveptr);
        }
        doc[p_count - 1] = current_paragraph;
        free(p_copy);
        p_token = strtok_r(NULL, "\n", &p_saveptr);
    }
    free(text_copy);
    return doc;
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

void print_word(char* word) {
    printf("%s", word);
}

void print_sentence(char** sentence) {
    int word_count;
    scanf("%d", &word_count);
    for(int i = 0; i < word_count; i++){
        printf("%s", sentence[i]);
        if( i != word_count - 1)
            printf(" ");
    }
} 

void print_paragraph(char*** paragraph) {
    int sentence_count;
    scanf("%d", &sentence_count);
    for (int i = 0; i < sentence_count; i++) {
        print_sentence(*(paragraph + i));
        printf(".");
    }
}

int main() 
{
    char* text = get_input_text();
    char**** document = get_document(text);

    int q;
    scanf("%d", &q);

    while (q--) {
        int type;
        scanf("%d", &type);

        if (type == 3){
            int k, m, n;
            scanf("%d %d %d", &k, &m, &n);
            char* word = kth_word_in_mth_sentence_of_nth_paragraph(document, k, m, n);
            print_word(word);
        }

        else if (type == 2){
            int k, m;
            scanf("%d %d", &k, &m);
            char** sentence = kth_sentence_in_mth_paragraph(document, k, m);
            print_sentence(sentence);
        }

        else{
            int k;
            scanf("%d", &k);
            char*** paragraph = kth_paragraph(document, k);
            print_paragraph(paragraph);
        }
        printf("\n");
    }     
}
