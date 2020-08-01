#include <iostream>
#include <sstream>
#include <thread>

#include "LetterPointTable.hpp"
#include "LetterBag.hpp"
#include "LetterOfPlayer.hpp"
#include "Gaddag.hpp"
#include "board.hpp"
#include "AIScrabble.hpp"

using namespace std;

string exec_path(char** argv_)
{
    string path(*argv_);

    while (!path.empty() && (path.back() != '/' && path.back() != '\\'))
        path.pop_back();

    while (!path.empty() && (path.back() == '/' || path.back() == '\\'))
        path.pop_back();
    
    return (path);
}

inline void place_kick_to_board(Board& brd_, KicksInformation const& k_)
{
    assert(k_.coord.x >= 0);
    assert(k_.coord.y >= 0);

    KicksInformation const formatedKick = k_.format();
    int const   step_x = (k_.d == e_direction::horizontal ? 1 : 0),
                step_y = (k_.d == e_direction::vertical ? 1 : 0);

    Vec2i       v = formatedKick.coord;
    unsigned    i = 0;

    while (v.x < brd_.getWidth() && v.y < brd_.getHeigth() &&
           i < formatedKick.word.size())
    {
        brd_.at(v).letter = formatedKick.word[i];

        v.x += step_x;
        v.y += step_y;
        ++i;
    }
}

int main(int argc, char** argv_)
{
    cout << "regression LetterPointTable ... " << flush;
    LetterPointTable::test_regression();
    cout << "Ok" << endl;

    cout << "regression LetterBag ... " << flush;
    LetterBag::test_regression();
    cout << "Ok" << endl;

    cout << "regression LetterOfPlayer ... " << flush;
    LetterOfPlayer::test_regression();
    cout << "Ok" << endl;

    Gaddag              gdg(exec_path(argv_) + "/" + "../data/dico/fr.txt");
    LetterPointTable    tabLetterPoint;
    Board               brd;
    LetterBag           letterBag;

    AIScrabble  ai0(&gdg, &letterBag, &tabLetterPoint, &brd),
                ai1(&gdg, &letterBag, &tabLetterPoint, &brd),
                ai2(&gdg, &letterBag, &tabLetterPoint, &brd),
                ai3(&gdg, &letterBag, &tabLetterPoint, &brd);

    AIScrabble* const   tabAI[4] = {&ai0, &ai1, &ai2, &ai3};
    int tabScore[4] = {0, 0, 0, 0};

    while (!letterBag.isEmpty())
    {
        for (int i = 0; i < 4; ++i)
        {
//            this_thread::sleep_for(chrono::milliseconds(1000));
            cout << "Pause... (appuyer sur entree pour continuer)" << endl;
            getchar();

            tabAI[i]->play();

            system("clear");

            cout << brd << endl;

            //  Afficher le résultat
            for (int j = 0; j < 4; ++j)
            {
                cout << (i == j ? ">> " : "   ") << "AI " << j
                     << " : score = " << tabAI[j]->getScore()
                     << ",\tleft_letters = '" <<
                    tabAI[j]->getLetterOfPlayer().getListOfLetters() << "'\n";
            }
        }
    }

    return (0);
}
