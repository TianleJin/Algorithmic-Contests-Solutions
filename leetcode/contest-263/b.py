from typing import List


class Bank:

    def __init__(self, balance: List[int]):
        self.n = len(balance)
        self.balance = balance

    def exists(self, account):
        return 1 <= account <= self.n
    
    def enough(self, account, money):
        return self.balance[account - 1] >= money
    
    def transfer(self, account1: int, account2: int, money: int) -> bool:
        if not self.exists(account1) or not self.exists(account2) or not self.enough(account1, money): 
            return False
        
        self.balance[account1 - 1] -= money
        self.balance[account2 - 1] += money
        return True

    def deposit(self, account: int, money: int) -> bool:
        if not self.exists(account):
            return False
        
        self.balance[account - 1] += money
        return True

    def withdraw(self, account: int, money: int) -> bool:
        if not self.exists(account) or not self.enough(account, money):
            return False
    
        self.balance[account - 1] -= money
        return True


# Your Bank object will be instantiated and called as such:
# obj = Bank(balance)
# param_1 = obj.transfer(account1,account2,money)
# param_2 = obj.deposit(account,money)
# param_3 = obj.withdraw(account,money)