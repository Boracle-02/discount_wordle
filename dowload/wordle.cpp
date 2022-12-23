#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <string>
#include <iterator>
#include <fstream>
#include <random>
#include <ctime>

// not the best 
using namespace std;

string chose( vector<string> & v ){
    
    int randx = rand() % v.size();
    cout << randx << endl;
    return v[randx];
}

void update_past_words( const set<string> & past_words )
{
    // with prev code confirmed it adds it into and makes sure no dupes
    ofstream on("past_words.txt");
    for (auto x : past_words)
    {
            on << x << endl;
    }
}

void clear_past_words( set<string> & past )
{
    // confirm works past_words.txt is empty
    past.clear();
    update_past_words(past);
}

bool can_still_guess( const set<string> & past )
{
    return past.size() <= 6;
}

bool check_valid_answer( const string & guess, const set<string> & past_guesses, const vector<string> & allowed_guesses )
{
    // check valid first if not -> false if yes -> check in past_guesses
    if ( find( allowed_guesses.begin(), allowed_guesses.end(), guess ) != allowed_guesses.end() )
    {
        // to use find with vector have to do above way
        if (past_guesses.find( guess) == past_guesses.end() )
        {
            return true;
        }
    }
    // removed else so i dont need a return false inside nested if statement above
        return false;
}

void mappify( map<char, int> & ret, const string & word ){
    for ( int i = 0; i < word.length(); i++ ){
        if ( ret.find(word[i]) == ret.end() ){
            ret.insert({word[i], 1});
        }
        else{
            ret.find(word[i])->second++;
        }
    }
}

string reply_message( const string & guess, const string & todays_wordle)
{
    // only call this when i have used check_valid_answer
    // therefore no need to check past answers
    // a string will consist of:
    // 0 - denote letter at spot is not in the word
    // 1 - letter is in the word but in wrong spot
    // 2 - letter is in the word and right spot
    string return_val;

    // examples: 
    // twine
    // spiny
    // 00220

    // aarde
    // btrea
    // 00211

    // btrea
    // aarde
    // 10201

    // create a dict?

    map<char, int> first_word;
    map<char, int> second_word;
    mappify(first_word, todays_wordle);
    mappify(second_word, guess);

    for ( int i = 0; i < todays_wordle.length(); i++ ){
        
    }
    
    return return_val;
}

void menu()
{
    cout << "Wordle by me :3" << endl;
    
}

int main()
{
    srand( time(0) );
    vector<string> answers;
    vector<string> allowed;
    set<string> past_words;
    set<string> past_guesses;
    
    ifstream in_ans("answers.txt");
    ifstream in_guess("allowed_guesses.txt");

    copy( istream_iterator<string>(in_ans), istream_iterator<string>(), back_inserter(answers) );
    copy( istream_iterator<string>(in_guess), istream_iterator<string>(), back_inserter(allowed) );
    
    // confirmed gets all answers
    // for( string i : answers ){ cout << i << endl; }

    // instead of how wordle does it and just use the next wordle, I want to select a random word to do it
    // have a file store all past words then I can store in that in case I terminate so it will save?
    // so i have a vector of words there then I can take the difference of vector of possible words and written words?

    ifstream in_past("past_words.txt");
    
    // remember past_words is a set not vector so have to do this and not back_insterter
    copy( istream_iterator<string>(in_past), istream_iterator<string>(), inserter(past_words, past_words.begin() ) );
    
    // ig just change answers? --> worth to turn into method?
    /*
    remove_if(answers.begin(), answers.end(), [&](string & c){ 
        return find(past_words.begin(),  past_words.end(), c );
    } );
    */

   for (int i = 0; i < 1; ++i ){
        string todays_wordle = chose(answers);

        cout << todays_wordle << endl << endl;
        past_words.insert(todays_wordle);

        
   }

    return 0;
}
