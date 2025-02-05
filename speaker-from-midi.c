/*
This file doesn't currently work as I want it to, i.e. load a file that is persistently
within the robot because i don't know about it's functionality currently. All it does
is print out the frequencies and times into a format similar to a C array so it can be
implemented into the actual robot program. Will be updated when im familiar with the robots functionality
*/

#include <stdio.h>
#include <stdlib.h>

struct Note // Note struct
{
    int frequency;
    int time;
};

struct Note *read_from_output() // Reads the note from the output.txt file
{
    struct Note *notes = malloc(100 * sizeof(struct Note));

    int frequency = 0;
    int time = 0;

    FILE *file = fopen("../output.txt", "r"); // opens the output.txt file
    if (file == NULL)
    {
        perror("Error opening file"); // If the file doesn't exist then error
    }

    int count = 0;
    while (fscanf(file, "%d;%d", &frequency, &time) != EOF) // reads through the file
    {
        if (frequency == 0 && time == 0)
        {
            break; // if note is empty then stop
        }
        notes[count].frequency = frequency; // gets the frequency from each note
        notes[count].time = time;           // gets the time from each note
        count++;
    }
    fclose(file);
    return notes;
}

int play_sound() // Plays the sound from notes struct
{
    struct Note *notes = read_from_output();
    int note_count = 0;
    printf("int freq[] = {");
    while (notes[note_count].frequency != 0 && notes[note_count].time != 0)
    {
        if (note_count > 0)
        {
            printf(", ");
        }
        printf("%d", notes[note_count].frequency); // prints frequency
        note_count++;
    }
    printf("};\n");

    note_count = 0;
    printf("int time[] = {");
    while (notes[note_count].frequency != 0 && notes[note_count].time != 0)
    {
        if (note_count > 0)
        {
            printf(", ");
        }
        printf("%d", notes[note_count].time); // prints time
        note_count++;
    }
    printf("};");
    free(notes);
}

int main()
{
    play_sound();
}