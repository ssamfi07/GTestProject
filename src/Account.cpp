#include <exception>
#include <iostream>

#include "Account.hpp"

namespace bank
{
    Account::Account():balance_(0){};
    Account::Account(int value):balance_(value){};

    void Account::Deposit(float amount)
    {
        balance_ += amount;
    }

    void Account::Withdraw(float amount)
    {
        balance_ -= amount;
    }

    void Account::TransferFunds(Account& destination, float amount)
    {
        destination.Deposit(amount);
        Account::Withdraw(amount);
    }

    Account Account::TransferMinFunds(Account& destination, float amount)
    {
        std::cout << "smth";
        try
        {
            if(balance_ - amount > minBalance_)
            {
                Account::TransferFunds(destination, amount);
                throw("Transfer Completed");
            }
            else
            {
                throw ("Not Enough Funds");
            }
        }
        catch(std::exception& e)
        {
            std::cout << e.what() << std::endl;
        }
        return destination;
    }

} // namespace bank