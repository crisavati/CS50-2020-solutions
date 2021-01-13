#include <cs50.h>
#include <stdio.h>
#include <string.h>

bool vote(string people[], string name, int n);

int main(void)
{
    string people[3] = {"Al", "Bob", "Charlie"};

    // Loop over all voters
    for (int i = 0; i < 3; i++)
    {
        string name = get_string("Vote: ");

        // Check for invalid vote
        if (!vote(people, name, 3))
        {
            printf("Invalid vote.\n\n");
        }
    }
}

// Update vote totals given a new vote
bool vote(string people[], string name, int n)
{
    for (int i = 0; i < n; i++)  // linear search for the name
    {
        printf("In array name: %s\n", people[i]);

        if(strcmp(people[i], name) == 0)
        {
            printf("Voted for %s, people[i] was %s\n\n", name, people[i]);
            return true;
        }
    }
    return false;
}
