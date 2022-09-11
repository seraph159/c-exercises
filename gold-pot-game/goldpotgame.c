#include <stdio.h>
#include <ctype.h>
#include <string.h>


#define NROWS 11
#define NCOLS 11
#define START_R (NROWS/2)
#define START_C (NCOLS/2)


#define NORTH 'n'
#define SOUTH 's'
#define EAST  'e'
#define WEST  'w'
#define QUIT  'q'
#define BLANK 'b'
#define ERROR 'r'


 /**
  * func:  read_cmd
  * desc:  (attempts to) read a single line from standard input, and
  *          returns one of the following:
  *
  *          NORTH : if the first non-whitespace character is either
  *                  'n' or 'N'
  *          SOUTH : if the first non-whitespace character is either
  *                  's' or 'S'
  *          EAST  : if the first non-whitespace character is either
  *                  'e' or 'E'
  *          WEST  : if the first non-whitespace character is either
  *                  'w' or 'W'
  *          QUIT  : if the first non-whitespace character is either
  *                  'q' or 'Q' OR an input line cannot be read (this
  *                  happens if EOF is read terminating the input; from
  *                  the terminal, this happens if the user types ctrl-D
  *                  (in UNIX at least))
  *          BLANK : if the user entered a blank/empty line
  *          ERROR : if the user entered an invalid command
  *
  */

char read_cmd() {

    char buf[128];

    // this happens when fgets reads 'EOF'.  This happens
    //   when the user types CTRL-D
    if (fgets(buf, 128, stdin) == NULL)
        return 'q';

    int n = strlen(buf);

    int i = 0;

    while (i < n && isspace(buf[i]))
        i++;

    if (i == n)
        return BLANK;  // entire line is whitespace (incl newline)
    char c = buf[i];

    switch (c) {
    case 'n':
    case 'N': return NORTH;
    case 's':
    case 'S': return SOUTH;
    case 'e':
    case 'E': return EAST;
    case 'w':
    case 'W': return WEST;
    case 'q':
    case 'Q': return QUIT;
    default:
        return ERROR;

    }
}

/**
 * func: inrange
 * desc: simple predicate function determining whether a
 *          given coordinate (r,c) is within the boundaries
 *          of the "board" (if yes, returns true; if no,
 *          returns false).
 */
int inrange(int r, int c) {
    if (r < 0 || c < 0 || r >= NROWS || c >= NCOLS)
        return 0;
    else
        return 1;
}

int main(int argc, char* argv[]) {
    int g_row = 0, g_col = 0;
    int randomize = 1;
    time_t t;

    for (int i = 0; i < argc; i++) {
        printf(" argv[%i] : '%s'\n", i, argv[i]);
    }

    if (argc == 3) {
        int r1 = sscanf(argv[1], "%i", &g_row);  // row coord of gold
        int r2 = sscanf(argv[2], "%i", &g_col);  // row coord of gold
        if (r1 == 0 || r2 == 0 || !inrange(g_row, g_col) ||
            (g_row == START_R && g_col == START_C))
            printf("bad cmd-line args: using random location for gold\n");
        else
            randomize = 0;
    }
    else if (argc != 1)
        printf("bad cmd-line args: using random location for gold\n");

    if (randomize) {
        // your code or function call here to establish randomized location
        // for the pot-o-gold under requirements of handout

        srand((unsigned)time(&t));

        for (int i = 0; i < 2; i++) {
            if (i == 0)
                g_col = rand() % 11;
            else
                g_row = rand() % 11;
        }
    }

    //fprintf(stderr, "pot-o-gold location: (%d, %d)\n", g_row, g_col);

    int done = 0;
    int tflag = 1;
    int p_row = 5, p_col = 5; // store row and column of player's position
    int temp_row, temp_col;
    int proximityVar2, proximityVar1; // store proximity of player and gold position
    int movesCount = 0; // store total number of moves

    // demo loop...
    while (!done) {

        fprintf(stderr, "Direction: ");

        char c = read_cmd();

        if ((p_row == g_row) && (p_col == g_col)) {
            printf(" %s\n", "HOORAY!");
            printf("\n%s", "Total Number of Moves: ");
            printf("%d", movesCount);
            printf("\n%s", "GoodBye!");
            exit(0);
        }

        switch (c) {
        case 'n':
            p_col--; 
            break;
        case 's':
            p_col++;
            break;
        case 'w':
            p_row--;
            break;
        case 'e':
            p_row++;
            break;
        case 'b':
            printf(" INVALID INPUT!\n");
            break;
        case 'r':
            printf(" INVALID INPUT!\n");
            break;
        }

        if (p_row < 0) {
            printf("%s\n", " OUCH!");
            p_row++;
        }
        else if (p_row > 10) {
            printf("%s\n", " OUCH!");
            p_row--;
        }

        if (p_col < 0) {
            printf("%s\n", " OUCH!");
            p_col++;
        }
        else if (p_col > 10) {
            printf("%s\n", " OUCH!");
            p_col--;
        }

        if (tflag) {
            temp_row = p_row;
            temp_col = p_col;
            proximityVar1 = ((g_row - 5) * (g_row - 5)) + ((g_col - 5) * (g_col - 5));

            tflag = 0;
        }


        proximityVar2 = ((g_row - p_row) * (g_row - p_row)) + ((g_col - p_col) * (g_col - p_col)); //calculate distance

        if (proximityVar2 < proximityVar1) {
            printf("%s\n", " GETTING WARMER!");
        }
        else if (proximityVar2 > proximityVar1) {
            printf("%s\n", " GETTING COLDER!");
        }

        temp_row = p_row;
        temp_col = p_col;
        proximityVar1 = ((g_row - temp_row) * (g_row - temp_row)) + ((g_col - temp_col) * (g_col - temp_col));

        movesCount++;

        if (c == 'q')
            done = 1;
    }

}

