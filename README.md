# MATH325 Path-Finder
This is a algorithm in C-code that takes in a walk of single digit integers of length *n* representing vertexes and turns it into a path from the first to the *n*th vertex. The way we can do this is by scanning the list for numbers and if there is a repeat number then we can collapse the sublist in the list and leaves only the repeated digit. For example: the list [1, 2, 3, 2, 4, 5, 7, 5, 6, 7, 9] would collapse into [1, 2, 4, 5, 7, 9], where no vertices are repeated.

I had done a similar project for a previous class that was meant to take in an array of colors and a color to be inserted at an index. It would then act as a [Zuma](https://en.wikipedia.org/wiki/Zuma_(video_game)) where it collapses the stack and finds more connections that that implosion could have created. 

Most of the code for this project was taken from my previous one, which will be linked **here** when I add it to a repo eventually.
