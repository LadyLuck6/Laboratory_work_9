#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX_LENGTH 1000//обмежений масив до 1000 сим.

int countWords(const char *text);//обчислює кк. слів у даному рядку
int countCharacters(const char *text);//обчислює кк. символів

int main() {
    char text[MAX_LENGTH];//масив для зберігання введеного тексту

    printf("Введіть текст: ");
    fgets(text, sizeof(text), stdin);//функція для зчитування тексту зі стандартного вводу

    int wordCount = countWords(text);//зберігається результат обчисл. кк. слів у рядку
    int charCount = countCharacters(text);//зберігається результат обчимл. кк. символів у рядку

    printf("Кількість різних слів: %d\n", wordCount);
    printf("Кількість використаних символів: %d\n", charCount);

    return 0;
}
//функція обчислює кк. слів у рядку
int countWords(const char *text) {
    int wordCount = 0;//для зберігання кк. слів
    int isWord = 0; // Флаг, що вказує, чи знаходиться в середині слова

    // Проходимось по кожному символу в рядку
    for (int i = 0; text[i] != '\0'; i++) // \0 кінець рядка
    {
        // Якщо поточний символ є буквою чи цифрою, то встановлюємо флаг, що ми в середині слова
        if (isalpha(text[i]) || isdigit(text[i])) {
            isWord = 1;
        }
        // Якщо поточний символ не є буквою чи цифрою, але флаг показує, що ми в середині слова,
        // то збільшуємо лічильник слів та скидаємо флаг
        else if (isWord) {
            wordCount++;
            isWord = 0;//Це означає, що ми вийшли з середини слова і готові обробляти наступні символи.
        }
    }

    return wordCount;//повертає підраховану кк. слів назад
}
//функція обчислює кк. символів у рядку
int countCharacters(const char *text) {
    int charCount = 0;

    // Проходимось по кожному символу в рядку
    for (int i = 0; text[i] != '\0'; i++) {
        // Якщо поточний символ не є символом нового рядка або символом кінця рядка,
        // то збільшуємо лічильник символів
        if (text[i] != '\n' && text[i] != '\0') {
            charCount++;
        }
    }

    return charCount;//повертає підраховану кк. символів назад.
}