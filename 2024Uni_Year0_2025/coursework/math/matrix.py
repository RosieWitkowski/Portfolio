"""Performs calculations on a matrix representing three branches of a supermarket chain."""

# Colours 
blue, cyan, reset = "\033[34m", "\033[36m", "\033[0m"

def main():
    # Rows 0,1,2 correspond to chains A, B, C; columns 0,1,2 to Milk, Bread, Eggs
    stock = [[50, 30, 20], [40, 60, 10], [30, 20, 40]]
    sales = [[20, 10, 5], [15, 20, 10], [10, 5, 15]]
    branches = ['A', 'B', 'C']

    # Display starting data
    rows, cols = len(stock), len(stock[0])
    print(f"Original stock: ")
    print_format(stock, branches, rows, cols, "")
    print(f"Sales this week: ")
    print_format(sales, branches, rows, cols, "")

    # Update stock using stock - number of sales
    stock = matrix_minus(stock, sales, rows, cols)
    print(f"Updated stock: ")
    print_format(stock, branches, rows, cols, "")

    # Amount of restocking required if maintaining a minimum 40 units of everything
    restock = scalar_minus(40, stock, rows, cols)
    print("Restocking needed: ")
    print_format(restock, branches, rows, cols, "")

    # Cost of restocking per branch, and the total cost
    cost, branches_cost, ttl = calculate_cost(restock, rows, cols)

    print("Cost of restocking per branch: ")
    print_list(branches_cost, branches, "Restocking cost", "£")

    print(f"~ Total restock cost of all branches: £{ttl} ~\n")


    # Revenue per branch in a week, and which branch performed the best
    gross_revenue, branch_revenues, best_branch, best = evaluate_performance(sales, rows, cols, cost)
    print("Gross revenue (per branch per week)")
    print_list(gross_revenue, branches, "Branch gross Revenue", "£")
    print("Net revenue (per branch per week): ")
    print_list(branch_revenues, branches, "Branch net revenue", "£")

    print(f"~ Best performing branch was branch {branches[best_branch]} at £{best} this week ~")

    return 1

##########################
# Longer actions functions

def calculate_cost(restock, rows, cols):
    # Prices x restock
    prices = [1.5, 1, .5]
    prices_matrix = [prices, prices, prices]

    cost  = matrix_multiply(prices_matrix, restock, rows, cols)

    # Cost of restocking per branch
    branches_costs = []
    for row in cost:
        branches_costs.append(sum(row))
    
    # Total cost
    ttl = sum(branches_costs)

    return cost, branches_costs, ttl

def evaluate_performance(sales, rows, cols, cost):
    # Gross revenue (sales price x number of sales)
    sale_prices = [2, 1.5, 1]
    sales_matrix = [sale_prices, sale_prices, sale_prices]

    gross_revenue = matrix_multiply(sales_matrix, sales, rows, cols)

    # Gross per branch
    branches_gross = []
    for row in gross_revenue:
        branches_gross.append(sum(row))

    # Net revenue  (gross revenue - cost)
    revenue = matrix_minus(gross_revenue, cost, rows, cols)

    # Net per branch
    branches_revenue = []
    for row in revenue:
        branches_revenue.append(sum(row))

    # Best performing branch
    best = max(branches_revenue)
    best_branch = branches_revenue.index(best)
        
    return branches_gross, branches_revenue, best_branch, best

############################
# Print formatting functions

def print_format(matrix, branches, rows, cols, special_formatting):
    column_title = ['Milk', 'Bread', 'Eggs']
    
    # Item headings
    print(f"  {blue}-----------------")
    print("  |", end = "")
    for title in column_title:
        print(title, end = " ")
    print("|", end = "")
    print(f"\n  -----------------{reset}")

    # Shop branches
    for i in range (rows):
        # Row title
        print(cyan, branches[i], reset, end = " | ")
        for j in range (cols):
            # Row item
            print(f"{special_formatting}{matrix[i][j]}", end = " ")
        print()
    
    print()
    return 1

def print_list(list, branches, column_title, special_formatting):
    # Item headings
    print(f"  {blue}~~~~~~~~~~~~~~~~~")
    print(f"  |{column_title}|")
    print(f"  ~~~~~~~~~~~~~~~~~{reset}")

    # Shop branches
    for i, object in enumerate(list):
        # Row title
        print(cyan, branches[i], reset, end = " | ")
        # Row item
        print(f"{special_formatting}{object}", end = " ")
        print()
    
    print()
    return 1

###############################
# Matrix calculations functions

# Subtracts a matrix from another matrix
def matrix_minus(matrix_1, matrix_2, rows, cols):
    ans = []
    # Inspects each row, looking at its column
    for i in range(rows):
        row = []
        for j in range(cols):
            # Subtracts the same position element from each matrix
            row.append(matrix_1[i][j] - matrix_2[i][j])
        # Adds completed new row 
        ans.append(row)

    return ans

# Subtracts a matrix from a scalar amount (for each element of that matrix)
def scalar_minus(scalar, matrix, rows, cols):
    ans = []
    # Inspects each row, looking at its column
    for i in range(rows):
        row = []
        for j in range(cols):
            # Subtracts matrix element from scalar
            row.append(scalar - matrix[i][j])
        # Adds completed new row 
        ans.append(row)

    return ans

# Multiplies a matrix by a matrix (of scalar elements)
def matrix_multiply(matrix_1, matrix_2, rows, cols):
    ans = []
    # Inspects each row, looking at its column
    for i in range(rows):
        row = []
        for j in range(cols):
            # Multiplies the same position element from each matrix
            row.append(matrix_1[i][j] * matrix_2[i][j])
        # Adds completed new row 
        ans.append(row)

    return ans 

if __name__ =="__main__":
    main()