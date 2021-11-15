# Outputs name of person that won auction

num_total_bids = int(input())
if num_total_bids<1 or num_total_bids>100: print ("Invalid number :("), exit()


position = []
name = []
amounts = []

biggest_bid = 0

#winner dict (end result)
winner = {
        "position" : 0,
        "name" : "",
        "amount" : 0
    }

#loops through participants
i = 0 
while i < num_total_bids:

    position.append(int(i))
    name.append(input())
    amounts.append(int(input()))

    if amounts[i]>=2000: print("Invalid amount :("), exit() 

    if int(amounts[i])<int(biggest_bid):
        break

    elif int(amounts[i]) > int(biggest_bid): 
        biggest_bid = amounts[i]
        winner["position"] = position[i]
        winner["name"]= name[i]
        winner["amount"] = amounts[i]
    
    elif amounts[i] == int(biggest_bid):
        winner_pos = int(winner.get("position"))

        if position[i]<winner_pos:

            winner["position"] = position[i]
            winner["name"]= name[i]
            winner["amount"] = amounts[i]

        else:
            break

    if i == num_total_bids: break

    i += 1

#prints winner
print(winner.get("name"))
    