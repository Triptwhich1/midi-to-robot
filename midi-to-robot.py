import tkinter as tk
from tkinter import filedialog, messagebox
import mido
import os

notes = [
    'A0', 'A#0', 'B0',
    'C1', 'C#1', 'D1', 'D#1', 'E1', 'F1', 'F#1', 'G1', 'G#1', 'A1', 'A#1', 'B1',
    'C2', 'C#2', 'D2', 'D#2', 'E2', 'F2', 'F#2', 'G2', 'G#2', 'A2', 'A#2', 'B2',
    'C3', 'C#3', 'D3', 'D#3', 'E3', 'F3', 'F#3', 'G3', 'G#3', 'A3', 'A#3', 'B3',
    'C4', 'C#4', 'D4', 'D#4', 'E4', 'F4', 'F#4', 'G4', 'G#4', 'A4', 'A#4', 'B4',
    'C5', 'C#5', 'D5', 'D#5', 'E5', 'F5', 'F#5', 'G5', 'G#5', 'A5', 'A#5', 'B5',
    'C6', 'C#6', 'D6', 'D#6', 'E6', 'F6', 'F#6', 'G6', 'G#6', 'A6', 'A#6', 'B6',
    'C7', 'C#7', 'D7', 'D#7', 'E7', 'F7', 'F#7', 'G7', 'G#7', 'A7', 'A#7', 'B7',
    'C8'
]
frequencies = [
    27, 29, 31,
    33, 35, 37, 39, 41, 44, 46, 49, 52, 55, 58, 62,
    65, 69, 73, 78, 82, 87, 92, 98, 104, 110, 117, 123,
    131, 139, 147, 156, 165, 175, 185, 196, 208, 220, 233, 247,
    262, 277, 294, 311, 330, 349, 370, 392, 415, 440, 466, 494,
    523, 554, 587, 622, 659, 698, 740, 784, 831, 880, 932, 988,
    1047, 1109, 1175, 1245, 1319, 1397, 1480, 1568, 1661, 1760, 1865, 1976,
    2093, 2217, 2349, 2489, 2637, 2794, 2960, 3136, 3322, 3520, 3729, 3951,
    4186
]


def get_midi_file():
    messagebox.showinfo("Midi to Notes", "Choose a MIDI file to convert")
    file = filedialog.askopenfilename(title='MIDI file selection', filetypes=[('MID files', '*.mid')])
    if not file:
        return None
    return file

def main():
    midi_file_path = get_midi_file()
    if not midi_file_path:
        return

    midi_file = mido.MidiFile(midi_file_path)
    if os.path.exists('output.txt'):
        os.remove('output.txt')
    for track in midi_file.tracks:
        print(f'Track: {track.name}')
        for msg in track:
            if msg.type == 'note_on':
                note = (msg.note-21)
                time = msg.time
                with open(f'output.txt', 'a') as f:
                    f.write(f'{frequencies[note]};{time}\n')
                    

if __name__ == "__main__":
    root = tk.Tk()
    root.withdraw()  # Hide the root window
    main()




