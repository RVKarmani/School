#!/usr/bin/env python
# -*- coding: utf-8 -*-


import speech_recognition as sr

# obtain path to "english.wav" in the same folder as this script
from os import path
#AUDIO_FILE = path.join(path.dirname(path.realpath(__file__)), "sample.flac")
AUDIO_FILE = path.join(path.dirname(path.realpath(__file__)), "french.aiff")
#AUDIO_FILE = path.join(path.dirname(path.realpath(__file__)), "english.wav")

# use the audio file as the audio source
r = sr.Recognizer()
with sr.AudioFile(AUDIO_FILE) as source:
    audio = r.record(source)  # read the entire audio file

# recognize speech using Sphinx
try:
    print("Sphinx thinks you said " + r.recognize_sphinx(audio))
except sr.UnknownValueError:
    print("Sphinx could not understand audio")
except sr.RequestError as e:
    print("Sphinx error; {0}".format(e))

# recognize keywords using Sphinx
#try:
#    print("Sphinx recognition for \"one two three\" with different sets of keywords:")
#    print(r.recognize_sphinx(audio_en, keyword_entries=[("one", 1.0), ("two", 1.0), ("three", 1.0)]))
#    print(r.recognize_sphinx(audio_en, keyword_entries=[("wan", 0.95), ("too", 1.0), ("tree", 1.0)]))
#    print(r.recognize_sphinx(audio_en, keyword_entries=[("un", 0.95), ("to", 1.0), ("tee", 1.0)]))
#except sr.UnknownValueError:
#    print("Sphinx could not understand audio")
#except sr.RequestError as e:
#    print("Sphinx error; {0}".format(e))
