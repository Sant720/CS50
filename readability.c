#include <stdio.h>
#include <cs50.h>
#include <unistd.h>
#include <math.h>
#include <string.h>

int countLetters(int l, string s);
int countWords(int l, string s);
int countSentences(int l, string s);
int calcGrade(int l, int w, int s);
int letters, words, sentences, grade;


int main(void)
{
    string text = get_string("Text: ");
    // printf("%s\n", text);

    int lenght = strlen(text);

    countLetters(lenght, text);
    countWords(lenght, text);
    countSentences(lenght, text);
    
    // printf("%i letter(s)\n", letters);
    // printf("%i word(s)\n", words);
    // printf("%i sentence(s)\n", sentences);
    
    calcGrade(letters, words, sentences);

    if (grade >= 16)
    {
        printf("Grade 16+\n");
    }
    else if (grade <= 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", grade);
    }
}

int countLetters(int l, string s)
{
    for (int i = 0; i < l; i++)
    {
        if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z'))
        {
            letters++;
        }
    }
    return letters;
}

int countWords(int l, string s)
{
    for (int i = 0; i < l; i++)
    {
        if (s[i] == ' ')
        {
            words++;
        }
    }
    words++;

    return words;
}

int countSentences(int l, string s)
{
    for (int i = 0; i < l; i++)
    {
        if (s[i] == '.' || s[i] == '?'  || s[i] == '!')
        {
            sentences++;
        }
    }
    return sentences;
}

int calcGrade(int l, int w, int s)
{
    float avgL = (float) l / (float) w * 100;
    // printf("avgL: %f\n", avgL);
    float avgS = (float) s / (float) w * 100;
    // printf("avgS: %f\n", avgS);
    grade = round(0.0588 * avgL - 0.296 * avgS - 15.8);
    // printf("Index: %i\n", (int) grade);
    return grade;
}
