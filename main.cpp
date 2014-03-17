#include <iostream>
#include <unistd.h>

#include "Pingback.h"

using namespace std;

int main()
{
    Pingback *pingback = new Pingback("http://example.com/ping.php");
    pingback->setIdentifier("MyUniqueIdForThisAction");
    cout << "Hello world!" << endl;
    pingback->setParameter('a', "some-action-taking-huge-amount-of-time");
    cout << "Please wait..." << endl << "...Calculating huge data..." << endl;
    sleep(3);
    pingback->setParameter('r', "42");
    cout << "Done! Result is 42" << endl;
    pingback->send();
    return 0;
}
