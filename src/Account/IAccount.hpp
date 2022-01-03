#ifndef IACCOUNT_HPP
#define IACCOUNT_HPP

#include <iostream>

namespace bank 
{
class IAccount
{
public:
    IAccount(){}
    virtual ~IAccount() = default;
    virtual void Deposit(float amount) = 0;
    virtual void Withdraw(float amount) = 0;
};
} // namespace bank
#endif // IACCOUNT_HPP