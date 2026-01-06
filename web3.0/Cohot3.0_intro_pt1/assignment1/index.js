const crypto = require("crypto");

function getInputPrefix(prefix) {
  let index = 0;
  while (true) {
    const input = index.toString();
    const hash = crypto.createHash("sha256").update(input).digest("hex");
    if (hash.startswith(prefix)) {
      return { intput: input, hash: hash };
    }
    index++;
  }
}

const result = getInputPrefix('00000');
console.log(`Input: ${result.intput}`);
console.log(`Hash: ${result.hash}`);