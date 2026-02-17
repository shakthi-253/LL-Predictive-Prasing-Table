#include<stdio.h>
#include<string.h>

#define MAX 10

char production[MAX][10];
char first[MAX][10];
char follow[MAX][10];
char table[MAX][MAX][10];

int n;

int main() {

    printf("Enter number of productions: ");
    scanf("%d",&n);

    printf("Enter productions (Example: E=TR):\n");
    for(int i=0;i<n;i++)
        scanf("%s",production[i]);

    printf("\nEnter FIRST sets:\n");
    for(int i=0;i<n;i++) {
        printf("FIRST(%c): ",production[i][0]);
        scanf("%s",first[i]);
    }

    printf("\nEnter FOLLOW sets:\n");
    for(int i=0;i<n;i++) {
        printf("FOLLOW(%c): ",production[i][0]);
        scanf("%s",follow[i]);
    }

    for(int i=0;i<n;i++) {
        char nonterminal = production[i][0];
        char rhs = production[i][2];

        for(int j=0;j<strlen(first[i]);j++) {
            if(first[i][j] != '$') {
                table[nonterminal-'A'][first[i][j]-'a'][0] = nonterminal;
                table[nonterminal-'A'][first[i][j]-'a'][1] = '=';
                table[nonterminal-'A'][first[i][j]-'a'][2] = rhs;
                table[nonterminal-'A'][first[i][j]-'a'][3] = '\0';
            }
        }

        if(strchr(first[i],'$')) {
            for(int j=0;j<strlen(follow[i]);j++) {
                table[nonterminal-'A'][follow[i][j]-'a'][0] = nonterminal;
                table[nonterminal-'A'][follow[i][j]-'a'][1] = '=';
                table[nonterminal-'A'][follow[i][j]-'a'][2] = '$';
                table[nonterminal-'A'][follow[i][j]-'a'][3] = '\0';
            }
        }
    }

    printf("\nPredictive Parsing Table:\n");

    for(int i=0;i<MAX;i++) {
        for(int j=0;j<MAX;j++) {
            if(table[i][j][0] != '\0')
                printf("M[%c,%c] = %s\n", i+'A', j+'a', table[i][j]);
        }
    }

    return 0;
}