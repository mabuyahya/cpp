#include "Zombie.hpp"

int main(void)
{
    Zombie zombie("normal zombie");
    zombie.announce();
    Zombie *zombieOnTheHeap = zombie.newZombie("heapZombie");
    zombieOnTheHeap->announce();
    zombie.randomChump("ctack zombie");
    delete zombieOnTheHeap;
    return (1);
}