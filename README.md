# English

Sonic Guessture[1] is a puzzle game that was created in the winter semester 2014/15 at the [Audio-Video-Programming](https://rcl.blackpinguin.de/haw/bms/14ws/AVPRG/) compulsory elective course of [B.Sc. Media Systems (B-MS)](https://rcl.blackpinguin.de/haw/bms/).

The task was to develop an application to the topic 'Gesten steuern Musik' (engl.: music controlled by gestures). An acoustical puzzle game with gestures was made.

The player listens to broadly known music and has to guess which gesture might match the song. Guessing right, by making the gesture infront of the webcam, unlocks the next puzzle. The performance of the player will be rewarded with stars, in particular by being fast and solving the puzzle without optional hints.

Example[2]: the Overworld Theme from The Legend of Zelda requires the player to form a [Triforce](https://en.wikipedia.org/wiki/Triforce) with their hands.

Four gestures were programmed. Technically, the picture of the webcam is captured with OpenCV, the skin color[3] gets separated with color keying and the resulting bitmap gets analyzed for the gesture in question. Timing and rhytmic are additional recognition criteria for two of the gestures. Seperate threads in the Qt-Application are used for the GUI, music fading, camera capture, color keying, image analyzing and for the mediator[4], which are communicating with each other by an messaging system[5].

Together with projects from other students of this course, the game was exhibited on 2015-01-27. Sonic Guessture can't be released, because of missing rights of use for the music and images[6].

|                  |                                                                 |
| ---------------- | --------------------------------------------------------------- |
| __Languages__    | C++, UML                                                        |
| __Technologies__ | Qt 5, Multithreading, OpenCV, Color Keying, Gesture recognition |
| __Tools__        | GIMP, Dia                                                       |
| __IDE__          | Qt Creator                                                      |
| __Participants__ | 1                                                               |

### Footnotes

- [1]	Sonic: sound, speed, bang, video game figure
  
  Guessture: word combination of 'guess' and 'gesture'
- [2]	This example isn't a spoiler, because it is not part of the game. It merely illustrates the basic game idea.
- [3]	The individual skin color of the player will be picked once at the beginning of the game.
- [4]	Mediator-Pattern (GoF:273)
- [5]	Qt Signals and Slots
- [6]	Images are used to unravel puzzles after the correct gesture was recognized.

# Deutsch

Sonic Guessture[1] ist ein Rätselspiel, das im Wintersemester 2014/15 im Wahlpflichtfach [Audio-Video-Programmierung](https://rcl.blackpinguin.de/haw/bms/14ws/AVPRG/de.html) des Studienganges [Bachelor Media Systems (B-MS)](https://rcl.blackpinguin.de/haw/bms/de.html) erstellt wurde.

Aufgabe war es, ein Programm zum Thema 'Gesten steuern Musik' zu entwickeln. Entstanden ist ein akustisches Gestenrätsel.

Der Spieler bekommt bekannte Musikstücke zu hören und muss selbstständig den Bezug zu einer zum Stück passenden Geste herstellen, welche, bei erfolgreicher Ausführung vor der Webcam, das nächste Gestenrätsel freischaltet. Die Leistung des Spielers wird mit Sternen belohnt. Schnell sein und keine optional einblendbaren Hinweise benötigen bringt zusätzliche Sterne.

Beispiel[2]: bei dem Overworld Theme aus The Legend of Zelda soll der Spieler mit den Händen ein [Triforce](https://de.wikipedia.org/wiki/The_Legend_of_Zelda#Das_Triforce) formen.

Es wurden vier verschiedene Gesten programmiert. Technisch wird das Bild der Webcam mittels OpenCV abgegriffen, die Hautfarbe[3] mittels Color Keying herausgelöst und das resultierende binäre Bitmap auf die jeweilige Geste hin analyisiert. Zeit und Rhythmik sind ebenfalls Faktoren, die für zwei der Gesten eine Rolle spielen. Die Qt-Anwendung verwendet für GUI, Musiküberblendungen, Camera, Color Keying, Bildanalyse und Mediator[4] jeweils eigene Threads, die mittels Nachrichtensystem[5] miteinander kommunizieren.

Zusammen mit den Projekten der anderen Studierenden dieses Kurses wurde das Spiel am 27.01.2015 ausgestellt. Eine Veröffentlichung von Sonic Guessture ist aufgrund fehlender Musik- und Bildrechte[6] nicht möglich.

|                  |                                                             |
| ---------------- | ----------------------------------------------------------- |
| __Sprachen__     | C++, UML                                                    |
| __Technologien__ | Qt 5, Multithreading, OpenCV, Color Keying, Gestenerkennung |
| __Tools__        | GIMP, Dia                                                   |
| __IDE__          | Qt Creator                                                  |
| __Beteiligte__   | 1                                                           |

### Fußnoten

- [1]	Sonic: Schall, schnell, akustisch, Vi­deo­spiel­fi­gur
  
  Guessture: Wortkombination aus 'guess' (raten) und 'gesture' (Geste)
- [2]	Dieses Beispiel ist kein Spoiler und kommt nicht im Spiel vor. Es dient lediglich der Veranschaulichung der Spielidee.
- [3]	Die individuelle Hautfarbe des Spielers wird zu Beginn einmalig ausgewählt.
- [4]	Mediator-Entwurfsmuster (GoF:273)
- [5]	Qt Signals und Slots
- [6]	Bilder werden verwendet, um nach korrekter Erkennung der jeweiligen Geste das Rätsel aufzulösen.
