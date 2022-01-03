#ifndef ACCOUNT_HPP
#define ACCOUNT_HPP

#include "IAccount.hpp"

namespace bank 
{
class Account: public IAccount
{
private:
    float balance_;
    float minBalance_ = 10.0f;
public:
    Account();
    Account(int value);
    void Deposit(float amount) override;
    void Withdraw(float amount) override;
    void TransferFunds(Account& destination, float amount);
    Account TransferMinFunds(Account& destination, float amount);
};
} // namespace bank 

#endif // ACCOUNT_HPP