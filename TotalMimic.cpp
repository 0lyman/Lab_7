#include "TotalMimic.h"


TotalMimic::TotalMimic()
{
    testBit = false; // true for testing, false otherwise
}


TotalMimic::~TotalMimic()
{
    if (Prefixes.size() != 0)// if size not equal to zero delete items in the vector Prefixes and clear the vector
    {
        if (Prefixes.size() == 1)
        {
            delete &Prefixes[0];
            Prefixes.pop_back();
        }
        else
        {
            while (Prefixes.size() != 0)
            {
                delete &Prefixes[(Prefixes.size() - 1)];
                Prefixes.pop_back();
            }
        }
    }
}

//Part 1--------------------------------------------------------------
/**
* createMap
*
* Creates a prefix-suffix map based on the input text.
*
* Go through the input text and examine each group of 3 words. Refer
* to the first two words as the "prefix" and the third word as the
* "suffix". Create a map that associates each prefix with each suffix.
*  If you encounter a prefix that has been read already, add the new
*  suffix to the list of suffixes already associated with that prefix;
*  in this manner, each prefix can be associated with multiple
*  suffixes and even multiple copies of the same suffix. Note that
*  the input texts will only contain words separated by spaces.  Also
*  note that the last two word prefix in the text should be associated
*  with the suffix "THE_END".
*
* @param input
*                 the sample text to be mimicked
*/
void TotalMimic::createMap(string input)
{
    istringstream ss;
    ss.str(input);
    string word_one;
    string word_two;
    string word_three;
    ss >> word_one;  // get first three words
    if (testBit)
    {
        cout << "here is the input: " << input << endl;
    }
    if (testBit)
    {
        cout << "here is the first word: " << word_one << endl;
    }
    ss >> word_two;
    if (testBit)
    {
        cout << "here is the second word: " << word_two << endl;
    }
    ss >> word_three;
    if (testBit)
    {
        cout << "here is the third word: " << word_three << endl;
    }
    if (!ss.good())
    {

    }
    bool Go = true;
    do
    {
        istringstream PassMe;
        PassMe.str(word_one + " " + word_two);
        string Key = PassMe.str();
        if (testBit)
        {
            cout << "here is a Prefix 0: " << Key << endl;
            cout << "here is a Suffix 0: " << word_three << endl;
        }

        if (!doesPrefixExist(Key))
        {
            Prefixes.push_back(new MysteryMap<string, string>(Key, word_three));// first two become prefix and the third the suffix
        }
        else  // if prefix allready exists add suffix to it
        {
            Prefixes[getPrefixLocation(Key)]->addItem(word_three);
        }
        word_one.clear();
        word_one = word_two; // shift the words foreward into one and two
        if (testBit)
        {
            cout << "here is a word 1: " << word_one << endl;
        }
        word_two.clear();
        word_two = word_three;
        if (testBit)
        {
            cout << "here is a word 2: " << word_two << endl;
        }
        if (!ss.good())  // check if there are not more words in the string input
        {
            istringstream Passer;   // if no more words last two wors are the prefix and it is the end
            Passer.str(word_one + " " + word_two);
            string Key = Passer.str();
            string suffix = "THE_END";
            if (testBit)
            {
                cout << "key/Prefix before storage: "<< Key << endl;
                cout << "Suffix before storage: "<< suffix << endl;
                cout << "last Prefix" << endl;
            }
            if (!doesPrefixExist(Key))
            {
                if (testBit)
                {
                    cout << "here is a Prefix 1: " << Key << endl;
                    cout << "here is a Suffix 1: " << suffix << endl;
                }
                Prefixes.push_back(new MysteryMap<string, string>(Key, suffix));
            }
            else // if prefix allready exists add suffix to it
            {
                if (testBit)
                {
                    cout << "here is a Prefix 2: " << Key << endl;
                    cout << "here is a Suffix 2: " << suffix << endl;
                }
                Prefixes[getPrefixLocation(Key)]->addItem(suffix);
            }
            Go = false;
        }
        if (ss.good()) // check if there are more words in the string input
        {
            word_three.clear();
            ss >> word_three;   // get a new word for the third
            if (testBit)
            {
                cout << "here is a word 3: " << word_three << endl;
            }
        }
    }
    while (Go);
    if(testBit)
    {
        cout << " End read in "<<endl;
    }
}

/**
* getSuffixList
*
* Returns the list of suffixes associated with the given prefix.
* Returns an empty vector if the given prefix is not in the map or no
* map has been created yet.
*
* @param prefix
*                 the prefix to be found
* @return a list of suffixes associated with the given prefix if the
*                 prefix is found; an empty vector otherwise
*/
vector<string> TotalMimic::getSuffixList(string prefix)
{
    for (int x = 0; x < Prefixes.size(); x++)
    {
        if (prefix == Prefixes[x]->getKey())
        {
            return Prefixes[x]->getAllItems();
        }
    }
    vector<string> emptyVector(0);
    return emptyVector;
}
//Part 2--------------------------------------------------------------
/**
* generateText
*
* Generates random text using the map created by the createMap method.
*
* To generate the new text, start with the first prefix that was read
* and randomly select one of the suffixes associated with that prefix.
* The next prefix is the second word from the previous prefix and the
* selected suffix. Continue selecting random suffixes and building the
* next prefix until the suffix "THE_END" is selected. The token
* "THE_END" should not be returned as part of your generated text.
*
* @return random text generated using the map created with the sample
*                 text; an empty string if no map has been created yet
*/
string TotalMimic::generateText()
{

    string GeneratedText;
    if (Prefixes.size() != 0)
    {
        int nextPrefixIndex;
        bool stop = false;
        string NextPrefix;
        string junk;
        string firstHalfPrefix;
        string seccondHalfPrefix;
        GeneratedText = Prefixes[0]->getKey();  // set first words as the first Prefix
        if (testBit)
        {
            cout << "GeneratedText here 00: " << GeneratedText << endl;
        }
        istringstream Splitter;
        Splitter.str(Prefixes[0]->getKey());  // split the prefix into two words
        Splitter >> junk;
        if (testBit)
        {
            cout << "junk here 00: " << junk << endl;
        }
        Splitter >> firstHalfPrefix;
        if (testBit)
        {
            cout << "firstHalfPrefix here 00: " << firstHalfPrefix << endl;
        }
        seccondHalfPrefix = Prefixes[0]->getRandomItem();  // get a random suffix to put into the GeneratedText and use as the seccond half of the next prefix
        if (testBit)
        {
            cout << "seccondHalfPrefix here 00: " << seccondHalfPrefix << endl;
        }
        if (seccondHalfPrefix == "THE_END") // if the end return the GeneratedText
            return GeneratedText;
        else
        {
            GeneratedText = GeneratedText + " " + seccondHalfPrefix;   // if not "THE_END" put it into the GeneratedText string
            if (testBit)
            {
                cout << "GeneratedText here 01: " << GeneratedText << endl;
            }
            NextPrefix.clear();
            NextPrefix = firstHalfPrefix + " " + seccondHalfPrefix;  // combine to firstHalfPrefix and seccondHalfPrefix to find the next Prefix
            if (testBit)
            {
                cout << "NextPrefix here 01: " << NextPrefix << endl;
            }
            nextPrefixIndex = getPrefixLocation(NextPrefix);
        }
        do // loop and continue to generate randomized text until "THE_END" is generated
        {
            firstHalfPrefix.clear();
            firstHalfPrefix = seccondHalfPrefix;  // shift the seccond half to now be the first half
            seccondHalfPrefix.clear();
            seccondHalfPrefix = Prefixes[nextPrefixIndex]->getRandomItem();  // get a random suffix to put into the GeneratedText and use as the seccond half of the next prefix
            if (seccondHalfPrefix == "THE_END") // if the end return the GeneratedText
                stop = true;
            else
            {
                GeneratedText = GeneratedText + " " + seccondHalfPrefix;
                NextPrefix = firstHalfPrefix + " " + seccondHalfPrefix;  // combine to firstHalfPrefix and seccondHalfPrefix to find the next Prefix
                nextPrefixIndex = getPrefixLocation(NextPrefix);
            }
        }
        while (!stop);
    }
    return GeneratedText;
}

/*
Finds given Prefix (findPrefix) and returns index number
of the location in the vector Prefixes where Prefix is located
else return -1 if not found
*/
int TotalMimic::getPrefixLocation(string findPrefix)
{
    for (int x = 0; 0 < Prefixes.size(); x++)
    {
        if (findPrefix == Prefixes[x]->getKey())
            return x;
    }
}

/*
used to decide if Prefix allread exists or not
*/
bool TotalMimic::doesPrefixExist(string findPrefix)
{
    if (Prefixes.size() != 0)
    {
        for (int x=0; x < Prefixes.size(); x++)
        {
            if (findPrefix == Prefixes[x]->getKey())
                return true;
        }
    }
    return false;
}
