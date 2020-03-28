# gets how many total foods there are
n = int(input())

# creates food and food_count lists
foods = []
food_count = []
total_foods = []

# add every food into the food array
for i in range(n):
    foods.append(input())

# count each food and store them into the food_count list if they are not 0

if foods.count("Deluxe Tuna Bitz") != 0:

    food_count.append(foods.count("Deluxe Tuna Bitz"))
    total_foods.append("Deluxe Tuna Bitz")

if foods.count("Bonito Bitz") != 0:

    food_count.append(foods.count("Bonito Bitz"))
    total_foods.append("Bonito Bitz")

if foods.count("Sashimi") != 0:

    food_count.append(foods.count("Sashimi"))
    total_foods.append("Sashimi")

if foods.count("Ritzy Bitz") != 0:

    food_count.append(foods.count("Ritzy Bitz"))
    total_foods.append("Ritzy Bitz")


# loops through the entire food_count list
for i in range(len(food_count)):

    # sets the lowest value as the first value in the list
    highest = food_count[0]

    # creates variable to store the index of the lowest value
    highest_index = 0

    # loops through food_count list again and finds the lowest value
    for j in range(1, len(food_count)):

        # if the current element is lower than the first element, change that to the lowest element
        if food_count[j] > highest:

            # updates the lowest number
            highest = food_count[j]

            # records the index of the now lowest element
            highest_index = j

    print(str(total_foods[highest_index]) + " " + str(highest))
    food_count.pop(highest_index)
    total_foods.pop(highest_index)

