//Programmer: Henry C. Wong
//Date: 9/11/2021
//Description: Determines the cost of healing codemon balls at a codemon center.

#include<iostream>

using namespace std;


int main()
{
  
  const float KONTATAX=1;            // tax for the konta region
  const float JAHTATAX=.8;           // tax rate for he jahta region
  const float HAINNTAX=.95;          // tax rate for the hainn region
  const float SENNAHTAX=1.15;        // tax rate for the sennah region
  const float YNAVOTAX=1.5;          // tax rate for the ynavo region
  const float KOLASTAX=1.12;         // tax rate for the kolas region
  const float OLALOTAX=.75;          // tax rate for the olalo region
  const float GOLORTAX=2.5;          // tax rate for the golor region
  const int REGION_MAX = 8;          // max number of regions
  const int REGION_MIN = 1;          // minimum number of regions
  const int CODEBALL_COST = 90;      // cost of a code ball
  const int GOODBALL_COST = 115;     // cost of a good ball 
  const int EXTREMEBALL_COST = 130;  // cost of an exterme ball
  const int BUDGETBALL_COST = 50;    // cost of a budget ball
  const int BOUJEEBALL_COST = 350;   // cost of a bouje ball
  const int INSURANCE_MAX = 100;     // the highest the insurance rate can be
  const int INSURANCE_MIN = 0;       // the lowest the insurance rate can be
  const int BALL_NUM_MAX = 6;        // the maximum number of balls a coach can have 
  const int BALL_NUM_MIN = 0;        // the minimum the user can enter for number of balls
  const int BALL_TYPE_MAX = 5;       // the maximum number of ball types
  const int BALL_TYPE_MIN = 0;       // the minimum the user can enter for ball type
  const int KONTA_REGION_NUM = 1;    // number to represent the konta region
  const int JAHTA_REGION_NUM = 2;    // number to represent the jahta region
  const int HAINN_REGION_NUM = 3;    // number to represent the hainn region
  const int SENNAH_REGION_NUM = 4;   // number to represent the sennah region
  const int YNAVO_REGION_NUM = 5;    // number to represent the yanvo region
  const int KOLA_REGION_NUM = 6;     // number to represent the kola region
  const int OLALO_REGION_NUM = 7;    // number to represent the olalo region
  const int GOLOR_REGION_NUM = 8;    // number to represent the golor region
  const int CODEBALL_NUM = 1;        // number to represent code balls
  const int GOODBALL_NUM = 2;        // number to represent good balls
  const int EXTREMEBALL_NUM = 3;     // number to represent extreme balls
  const int BUDGETBALL_NUM = 4;      // number to represent budget balls
  const int BOUJEEBALL_NUM = 5;      // number to represent bouje balls
  const float CONVERSION_MOD = 11.0/17; //conversion modifier to exchange currencies
  const float CONVERSION_ADD = 3.62;    // conversion addition used to exchange currencies
  const float ROUNDING_VAR = 0.009;     // variable used for rounding
  int region;        
  bool coachInLine;
  float  insurance;
  int numOfBalls;
  int ballType;
  float totalCost = 0;
  bool hasBudgetBall = false;
  bool hasBoujeeBall = false;
  bool arrested = false;
  int ballCounter = 0;
  char hasInsurance;
  //for two point percision
  cout.setf(ios::fixed);
  cout.setf(ios::showpoint);
  cout.precision(2);

  
  cout << "Welcome to Wong's Fabulous Codecenter Price Gouger Calculator" << endl;
  //Region input
  cout << "What region are you using this program from?" << endl;
  cout << "1. Konta" << endl
       << "2. Jahta" << endl
       << "3. Hainn" << endl
       << "4. Sennah" << endl
       << "5. Ynavo" << endl
       << "6. Kolas" << endl
       << "7. Olalo" << endl
       << "8. Golor" << endl;
  

  do
  {
    cout << "Region: ";
    cin >> region;
  }while(region > REGION_MAX || region < REGION_MIN);

  do
  {
    // variable resets for each new coach
    totalCost = 0;
    hasBoujeeBall = false;
    hasBudgetBall = false;
    arrested = false;
    ballCounter = 0;

    do
    {
      cout << "Does the coach have insurance? ";
      cin >> hasInsurance;
    }while(hasInsurance != 'y' && hasInsurance != 'n');
    
    // insurance input
    if(hasInsurance == 'y')
    {
      do
      {
        cout << "What is this coach's insurance rate (0-100)? ";
        cin >> insurance;
      }while(insurance < INSURANCE_MIN ||  insurance > INSURANCE_MAX);
    }
    else
    {
      insurance = 0;
    }
    
    //request how many code balls the coach has
    do
    {
      cout << "How many codeballs does this coach need healed? (number between 1-6)";
      cin >> numOfBalls; //hehe
    }while(numOfBalls < BALL_NUM_MIN ||  numOfBalls > BALL_NUM_MAX);

    do
    {
      // user inputs what balls the coach has
      do
      {
        cout << "Which ball?" << endl;
        cout << "1. Code Ball" << endl
             << "2. Good Ball" << endl
             << "3. Extreme Ball" << endl
             << "4. Budget Ball" << endl
             << "5. Boujee Ball" << endl;
        cout << "Ball Type: ";
        cin >> ballType;
      }while(ballType > BALL_TYPE_MAX || ballType < BALL_TYPE_MIN);

      // if the coach has a budget and a boujee ball and comes from regions that end in an 'a' or 'o'

      if((region == KONTA_REGION_NUM || region == JAHTA_REGION_NUM || region == YNAVO_REGION_NUM || region == OLALO_REGION_NUM) && ((ballType == 4 && hasBoujeeBall) ||(ballType == 5 && hasBudgetBall)))
      {
        cout << "Authorities have been notified and the client will be arrested shortly" << endl;
        arrested = true;
      }
      else
          // calculate total cost
      {
          switch(ballType)
          {
            case CODEBALL_NUM:
              totalCost+= CODEBALL_COST;
              ballCounter++;
              break;
            case GOODBALL_NUM:
              totalCost += GOODBALL_COST;
              ballCounter++;
              break;
            case EXTREMEBALL_NUM:
              totalCost += EXTREMEBALL_COST;
              ballCounter++;
              break;
            case BUDGETBALL_NUM:
              totalCost += BUDGETBALL_COST;
              hasBudgetBall = true;
              ballCounter++;
              break;
            case BOUJEEBALL_NUM:
              totalCost += BOUJEEBALL_COST;
              hasBoujeeBall = true;
              ballCounter++;
              break;
            default:
              cout << "Not a ball option" << endl;
          }
      }
    }while((ballCounter < numOfBalls) && !arrested);
    // calculate tax
    switch(region)
    {
      case KONTA_REGION_NUM: 
        totalCost *= KONTATAX;
        break;
      case JAHTA_REGION_NUM:
        totalCost *= JAHTATAX;
        break;
      case HAINN_REGION_NUM:
        totalCost *= HAINNTAX;
        break;
      case SENNAH_REGION_NUM:
        totalCost *= SENNAHTAX;
        break;
      case YNAVO_REGION_NUM:
        totalCost *= YNAVOTAX;
        break;
      case KOLA_REGION_NUM:
        totalCost *= KOLASTAX;
        break;
      case OLALO_REGION_NUM: 
        totalCost *= OLALOTAX;
        break;
      case GOLOR_REGION_NUM:
        totalCost *= GOLORTAX;
        break;
    }

    if(!arrested)
    {
      // calculate insurance
      if(insurance != 0)
      {
        totalCost /= insurance;
      }
      // currency conversion
      totalCost = ((totalCost*(CONVERSION_MOD)) + CONVERSION_ADD);
      cout << "Total Cost: &" << totalCost + ROUNDING_VAR  << endl;

    }

    cout << "Are there any coaches left? (0 for no, 1 for yes)" << endl;
    cin >> coachInLine;
  }while(coachInLine);

  cout << "Good Bye!" << endl;

  return 0;
}
