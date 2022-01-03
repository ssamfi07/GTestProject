#include <stdexcept>
#include <iostream>

#include "Account.hpp"
#include "Logger.hpp"

namespace bank
{
    Account::Account():balance_(0){};
    Account::Account(int value):balance_(value){};

    void Account::Deposit(float amount)
    {
        // LOG_INFO << "Before " << __FUNCTION__ << " " << balance_;
        balance_ += amount;
    }

    void Account::Withdraw(float amount)
    {
        balance_ -= amount;
        // LOG_INFO << "After " << __FUNCTION__ << " " << balance_;
    }

    void Account::TransferFunds(Account& destination, float amount)
    {
        destination.Deposit(amount);
        Account::Withdraw(amount);
    }

    Account Account::TransferMinFunds(Account& destination, float amount)
    {
        // LOG_INFO << __FUNCTION__ << " " << this->balance_;
        try
        {
            if(balance_ - amount > minBalance_)
            {
                Account::TransferFunds(destination, amount);
            }
            else
            {
                throw std::out_of_range("Not Enough Funds");
            }
        }
        catch(std::out_of_range const& e)
        {
            LOG_WARNING << e.what();
        }
        return destination;
    }

} // namespace bank
