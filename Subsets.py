def subs(org_set):
    subsets = [[]]
    
    for item in org_set:
        new_subset = []
        
        for exist_subset in subsets:
            new_subset.append(exist_subset + [item])
            
        subsets.extend(new_subset)
        
    return subsets
    
    

numbers = {1,2,3}

results = subs(numbers)

print(f"Total subsets : {len(results)}")


print("\nSubsets along with the sum : ")
for s in results:
    print("\n")
    print(s)
    print(f"Sum : {sum(s)}")