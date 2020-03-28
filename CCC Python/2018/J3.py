cities = str(input())
#creates array to store all the cities
cities = [int (i) for i in cities.split()]

#array to store distances
citiesDistance = []

#calculates distance between given city and another city
totalDistance = 0

#starting city
for initialCity in range (len(cities)+1):

    #calculates distance from starting city to j
    for destinationCity in range (0, len(cities)+1):

        #checks if the cities are the same
        if initialCity == destinationCity:
            citiesDistance.append(0)

        else:

            #if the city is after the inital city
            if initialCity < destinationCity:

                #adds distances together
                for i in range (initialCity, destinationCity):
                    totalDistance += cities[i]
                citiesDistance.append(totalDistance)

                #resets total distance
                totalDistance = 0

            #if the city is before the intial city
            else:
                for i in range (destinationCity, initialCity):
                    totalDistance += cities[i]
                citiesDistance.append(totalDistance)

                #resets total distance
                totalDistance = 0


    print(' '.join(str(e) for e in citiesDistance))

    #clears the array
    citiesDistance = []