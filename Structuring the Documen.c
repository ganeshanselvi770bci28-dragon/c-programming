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
    doc.data = NULL;
    doc.paragraph_count = 0;
    
    char* text_copy = strdup(text);
    int p_count = 0;
    char* p_saveptr;
    char* p_token = strtok_r(text_copy, "\n", &p_saveptr);
    
    while (p_token != NULL) {
        doc.data = realloc(doc.data, (p_count + 1) * sizeof(struct paragraph));
        char* p_copy = strdup(p_token);
        int s_count = 0;
        doc.data[p_count].data = NULL;
        char* s_saveptr;
        char* s_token = strtok_r(p_copy, ".", &s_saveptr);
        
        while (s_token != NULL) {
            doc.data[p_count].data = realloc(doc.data[p_count].data, (s_count + 1) * sizeof(struct sentence));
            char* s_copy = strdup(s_token);
            int w_count = 0;
            doc.data[p_count].data[s_count].data = NULL;
            char* w_saveptr;
            char* w_token = strtok_r(s_copy, " ", &w_saveptr);
            
            while (w_token != NULL) {
                doc.data[p_count].data[s_count].data = realloc(doc.data[p_count].data[s_count].data, (w_count + 1) * sizeof(struct word));
                doc.data[p_count].data[s_count].data[w_count].data = strdup(w_token);
                w_count++;
                w_token = strtok_r(NULL, " ", &w_saveptr);
            }
            doc.data[p_count].data[s_count].word_count = w_count;
            free(s_copy);
            s_count++;
            s_token = strtok_r(NULL, ".", &s_saveptr);
        }
        doc.data[p_count].sentence_count = s_count;
        free(p_copy);
        p_count++;
        p_token = strtok_r(NULL, "\n", &p_saveptr);
    }
    doc.paragraph_count = p_count;
    free(text_copy);
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
