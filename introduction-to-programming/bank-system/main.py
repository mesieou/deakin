account = {
    "name": "Juan",
    "interest_rate": 0.05,
    "balance": 1000.0
}

def print_account(acc):
    print("\nAccount:", acc["name"])
    print("Rate:", acc["interestRate"], "%")
    print("Balance:", acc["balance"], "\n")

def deposit(acc):
    while True:
        amount = float(input("\nAmount deposited: "))
        if amount < 0:
            print("Please enter a value larger than or equal to 0")
        else:
            break
    acc["balance"] += amount
    print("Balance:", acc["balance"])


def withdraw(acc):
    while True:
        amount = float(input("\nAmount withdrawn: "))
        if amount < 0:
            print("Please enter a value larger than or equal to 0")
        else:
            break
    acc["balance"] -= amount
    print("Balance:", acc["balance"])

def add_interest(acc):
    days = int(input("\nInterest for how many days: "))
    daily_rate = acc['interestRate'] / 365.0
    interest_percent = daily_rate * days
    print(f"Rate is {acc['interestRate']}% PA = {interest_percent}%")
    
    interest_amount = (interest_percent / 100.0) * acc['balance']
    print(f"Interest = {interest_amount}")

    acc['balance'] += interest_amount
    print(f"Balance = {acc['balance']}")


# Main program
def main():
    acc = {}

    # Get initial account details
    acc['name'] = input("Enter account name: ")
    acc['interestRate'] = float(input("Enter interest percent (+/-): "))
    acc['balance'] = float(input("Enter initial amount: "))

    while True:
        # Display menu
        print("\nActions:")
        print("1: Print account details")
        print("2: Deposit")
        print("3: Withdraw")
        print("4: Add interest")
        print("5: Quit")
        option = input("Option: ")

        if option == "1":
            print_account(acc)
        elif option == "2":
            deposit(acc)
        elif option == "3":
            withdraw(acc)
        elif option == "4":
            add_interest(acc)
        elif option == "5":
            print("Goodbye!")
            break
        else:
            print("Invalid option. Please try again.")


if __name__ == "__main__":
    main()