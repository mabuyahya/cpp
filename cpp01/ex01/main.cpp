#include "Zombie.hpp"

int main(void)
{
    Zombie zombie("one big");
    Zombie *Zombies = zombie.zombieHorde(10, "ten small");
    for (int i = 0; i < 10; i++)
        Zombies[i].announce();
    delete[] Zombies;
    return (1);
}