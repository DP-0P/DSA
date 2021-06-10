LinearSearch = (search,array) => {
    let index = -1;
    console.log(array);
    console.log(array.length);
    for(let i=0;i<array.length;i++)
        if(array[i]===search)
            index=i; 

    if(index<0)
        console.log("Searched element is not available in array");
    else
        console.log("Searched element is available in array at index "+index);
};

let array = [1,2,5,4,3];
let search = 5;

LinearSearch(search,array);

// Time Complexity -
// Best Case - O(1)
// Worst Case - O(n)
// Average Case - O(n/2)

// Space complexity - O(1)
