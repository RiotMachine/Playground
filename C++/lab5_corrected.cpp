#include <iostream>
#include <string>
#include <vector>

// refactor of an absolutely horrid class assignment

class BankAccount 
{
public:
    enum Type
    {
        Checking,
        MoneyMarket,
        Savings,
    };

    friend std::ostream& operator<<(std::ostream& out, const Type t)
    {
        switch (t)
        {
        case Checking:    return out << "checking";
        case MoneyMarket: return out << "money market";
        case Savings:     return out << "savings";
        default:          return out << "???";
        }
    }

    static constexpr double s_minBalance{ 25.0 };

    BankAccount(const std::string& owner, Type t, double bal=0.0)
      : m_ownerName{ owner }, m_type{ t }, m_balance{ bal } {}

    std::string_view getOwnerName() const { return m_ownerName; }
    double getBalance() const             { return m_balance; }

    void deposit(double amount)  { m_balance += amount; }
    void withdraw(double amount) { m_balance -= amount; }
    void transfer(BankAccount& to, double amount)
    {
        this->withdraw(amount);
        to.deposit(amount);
    }

    friend std::ostream& operator<<(std::ostream& out, const BankAccount& acct)
    {
        return out << acct.m_ownerName << ": $" << acct.m_balance;
    }
    friend bool operator==(BankAccount& acct1, BankAccount& acct2)
    {
        return acct1.m_ownerName == acct2.m_ownerName 
            && acct1.m_type == acct2.m_type
            && acct1.m_balance == acct2.m_balance;
    }

private:
    std::string m_ownerName;
    Type m_type;
    double m_balance{ };
};

using Bank = std::vector<BankAccount*>;
double getAssets(const Bank& bank)
{
    double assets{ };
    for (const auto* account : bank)
        assets += account->getBalance();
    return assets;
}

int main()
{
    BankAccount a{ "Jordan", BankAccount::Checking, 500.0 };
    BankAccount b{ "Priya", BankAccount::Savings, 200.0 };
    Bank centralBank{ &a, &b };

    a.transfer(b, 150.0);
    std::cout << a << " | " << b << '\n';

    a.deposit(25.0);
    std::cout << a << '\n';

    std::cout << "Audit total: $" << getAssets(centralBank) << '\n';

    a.withdraw(50.0);
    std::cout << "Jordan balance after withdrawal: $" << a.getBalance() << '\n';

    std::cout << "Withdraw - Cash";
    b.withdraw(10.0);
    std::cout << '\n';

    BankAccount c("Bobby", BankAccount::Savings);
    std::cout << c 
              << (c.getBalance() >= BankAccount::s_minBalance ? " meets " : " does not meet ")
              << "the minimum balance\n";

    std::cout << a << " and " << a << " are "
              << (a == a ? "equal\n" : "not equal\n");
    std::cout << a << " and " << b << " are "
              << (a == b ? "equal\n" : "not equal\n"); 

    return 0;
}
