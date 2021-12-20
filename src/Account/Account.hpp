#ifndef ACCOUNT_HPP
#define ACCOUNT_HPP

namespace bank 
{

class Account
{
    private:
        float balance_;
        float minBalance_ = 10;
    public:
        Account();
        Account(int value);
        void Deposit(float amount);
        void Withdraw(float amount);
        void TransferFunds(Account& destination, float amount);
        Account TransferMinFunds(Account& destination, float amount);
};


} // namespace bank 

#endif // ACCOUNT_HPP