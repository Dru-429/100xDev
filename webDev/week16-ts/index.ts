
function greet(firstname: string) {
  console.log( `Hello ${firstname}`);
}

function sum(a: number, b: number){
  return a + b;
}

function first_elem(arr: number[]): number | null {
  if( arr.length > 0){
    return arr[0] ?? null;
  }
  return null;
}

let a = "Dhruv";
let b = 2;

console.log(sum(a,b));

greet("Dhruv");