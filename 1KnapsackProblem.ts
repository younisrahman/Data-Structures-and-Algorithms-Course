const knapsack = (w: number, wt: number[], val: number[], n: number) => {
  const arr = new Array(n + 1).fill(0).map(() => new Array(w + 1).fill(0));
  for (let item = 1; item < n + 1; item++) {
    for (let capacity = 1; capacity < w + 1; capacity++) {
      let maxValWithoutCurr = arr[item - 1][capacity];
      let maxValWithCurr = 0;
      let weightOfCurr = wt[item - 1];
      if (capacity >= weightOfCurr) {
        maxValWithCurr = val[item - 1];
        let remainingCapacity = capacity - weightOfCurr;
        maxValWithCurr += arr[item - 1][remainingCapacity];
      }
      arr[item][capacity] = Math.max(maxValWithoutCurr, maxValWithCurr);
    }
  }
  return arr;
};

let lengt = 10;
let num = 4;
let value = [20, 30, 10, 50];
let weight = [1, 3, 4, 6];
let mt = knapsack(lengt, weight, value, num);
console.log(mt[num][lengt]);
