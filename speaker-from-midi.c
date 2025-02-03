#include <stdio.h>
#include <stdlib.h>

struct Note
{
    int frequency;
    int time;
};

struct Note *read_from_output()
{
    struct Note *notes = malloc(100 * sizeof(struct Note));

    int frequency = 0;
    int time = 0;

    FILE *file = fopen("../output.txt", "r");
    if (file == NULL)
    {
        perror("Error opening file");
    }

    int count = 0;
    while (fscanf(file, "%d;%d", &frequency, &time) != EOF)
    {
        if (frequency == 0 && time == 0)
        {
            break;
        }
        notes[count].frequency = frequency;
        notes[count].time = time;
        count++;
    }
    fclose(file);
    return notes;
}

int play_sound() {
    struct Note *notes = read_from_output();
    int note_count = 0;
    printf("freq = {");
    while (notes[note_count].frequency != 0 && notes[note_count].time != 0)
    {
        if (note_count > 0) {
            printf(", ");
        }
        printf("%d", notes[note_count].frequency);
        note_count++;
    }
    printf("}\n");

    note_count = 0;
    printf("time = {");
    while (notes[note_count].frequency != 0 && notes[note_count].time != 0)
    {
        if (note_count > 0) {
            printf(", ");
        }
        printf("%d", notes[note_count].time);
        note_count++;
    }
    printf("}");
    free(notes);
}

int main() {
    play_sound();
}