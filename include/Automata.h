#ifndef INCLUDE_AUTOMATA_H_
#define INCLUDE_AUTOMATA_H_
#include <vector>
#include <string>
class Automata {
   public:
      enum State {
         OFF,
         WAIT,
         ACCEPT,
         CHECK,
         COOK
      };
      
   private:
      long int cash;
      std::vector<std::string> menu;
      std::vector<int> prices;
      std::vector<int> longitudes;
      State state;
      int menuEntry;
   
   public:
      Automata();
      void on();
      void off();
      void coin(int);
      void getMenu();
      State getState();
      void choice(int);
      void cancel();
   
   private:
      void check(int);
      void cook(int);
      void finish(int);
};

#endif
