#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// Solution should technically work but it times out on test 3
// Looked at tutorial and there are loads of pointers, I will probably complete this later

struct Person {
    int id;
    int sociability;
};

bool compare(Person person1, Person person2) {
    return person1.sociability < person2.sociability;
}

int validPeople(vector<Person> people) {
    int valid = 0;
    for (int i = 0; i < people.size(); i++) {
        if (people[i].sociability > 0)
            valid++;
    }
    return valid;
}

void solution() {
    int n;
    cin >> n;
    vector<Person> people;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        Person person;
        person.id = i+1;
        person.sociability = a;
        people.push_back(person);
    }
    vector<string> output;
    while (validPeople(people) > 1) {
        sort(people.begin(), people.end(), compare);
        while (people.front().sociability == 0)
            people.erase(people.begin());
        people.front().sociability--;
        people.back().sociability--;
        string talk = to_string(people.front().id) + " " + to_string(people.back().id); 
        output.push_back(talk);
    }
    cout << output.size() << "\n";
    for (int i = 0; i < output.size(); i++) {
        cout << output[i] << "\n";
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
        solution();
}