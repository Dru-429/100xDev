dated:  07 Jan 2025

link:      [Class 1 - History of blockchains](https://www.notion.so/Class-1-History-of-blockchains-2ec7dfd10735807d8d97ee6aaf35d70d?pvs=21) 

- Issues with classical currencies: Price drop| Centralized bodies controlling
- Only the Gold and Properties are the real assets
- But prob with them LIMITED  + Val shifted from contrary to contrary ( gold: 3-5%)
- FIX: Digital gold-like things: BTC White Paper
- Bitcoin: Introducing a way to build currency without a centralized bank,
- UInt8Array
    
    A better way to represent an array of bytes is to use a `UInt8Array` in JS
    
    ```jsx
    let bytes = new Uint8Array([0, 255, 127, 128]);
    console.log(bytes)
    ```
    
    How  Better: Less Space | Constraints
    
    - They use less space. Every number takes 64 bits (8 bytes). But every value in a `UInt8Array` takes 1 byte.
    - UInt8Array Enforces constraints - It makes sure every element doesn’t exceed 255.
    
- Encoding
    
    ## Ascii vs UTF-8
    
    - ASCII uses a 7-bit encoding scheme.
    - UTF-8 uses 1 to 4 bytes to encode each character.
    
    | Encoding type | Bits per character | Character set / idea | Human readability | Typical use cases | Notes [petal-estimate-4e9.notion](https://www.notion.so/Encodings-2ec7dfd1073580a5bdf0df85582537b1?pvs=21) |
    | --- | --- | --- | --- | --- | --- |
    | ASCII | 7 bits | Basic English letters, digits, symbols. | High (directly maps bytes to characters). | Legacy text, protocols, simple text data. | Every byte (0–127) corresponds to a visible or control character. [petal-estimate-4e9.notion](https://www.notion.so/Encodings-2ec7dfd1073580a5bdf0df85582537b1?pvs=21) |
    | Hex (Hexadecimal) | 4 bits per hex digit (8 bits per byte = 2 hex digits) | Digits 0–9 and letters A–F. | Medium (good for developers, compact). | Debugging, crypto, binary dumps, IDs. | One byte is represented as two hex characters like `48` for decimal 72. [petal-estimate-4e9.notion](https://www.notion.so/Encodings-2ec7dfd1073580a5bdf0df85582537b1?pvs=21) |
    | Base64 | 6 bits per character | A–Z, a–z, 0–9, `+`, `/` (plus `=` padding). | Medium (long strings but copy‑paste friendly). | Encoding binary for text channels (email, JSON, URLs with tweaks). | Each character represents one of 64 values; output is longer than original bytes. [petal-estimate-4e9.notion](https://www.notion.so/Encodings-2ec7dfd1073580a5bdf0df85582537b1?pvs=21) |
    | Base58 | ~5.86 bits per character | 58 chars: A–Z except I,O; a–z except l; digits 1–9 (no 0). | High (avoids confusing characters). | Crypto addresses (Bitcoin etc.), user‑facing tokens. | Designed to avoid visually similar characters like 0/O/I/l to reduce mistakes. [petal-estimate-4e9.notion](https://www.notion.so/Encodings-2ec7dfd1073580a5bdf0df85582537b1?pvs=21) |

- Hashing
    
    ```
    Helllo  ----------------------> asd9112kdas9cas1kfsfgrtjrtugd
    						hashing algo
    ```
    
    I/p data —> Algo —> A string that looks like ass
    
    Common hashing algorithms - SHA-256, MD5
    
    - Differences b/w md5 and sha-256MD5
        
        
        | Feature | MD5 | SHA-256 |
        | --- | --- | --- |
        | Output size | 128 bits (32 hex characters) | 256 bits (64 hex characters) |
        | Speed | Very fast | Slower than MD5 (but still fast) |
        | Security | Broken (not secure) | Strong |
        | Collisions | Easy to generate (two inputs can share same hash) | Computationally infeasible with current technology |
        | Use in cryptography | Not recommended / ❌ Cryptography | ✅ Cryptography |
        | Password hashing | Not recommended / ❌ Password hashing | Can be used, often via stronger constructions (e.g. HMAC) |
        | Other uses today | Only non-security uses (e.g., quick checksums) | ✅ Digital signatures, ✅ Blockchain (e.g., Bitcoin) |
        | Overall status | Obsolete for security purposes | Recommended for modern security applications |
    - Condn for hashing:
        - Deterministic: Same i/p —> same o/p, so even small change in i/p a lot change in the output
        - Fast computation
        - Pre-image resistance, so u can’t backtrack it
    
- Encryption: leads to decryption, vice versa, while hashing not expected to
- eg: SHA-256

- Encryption
    
    ```
            Encryption                                  decryption
    hello ---------------> asdfggjkeofn777899fvdf9bv9----------------> hello
    					KEY                                           KEY
    ```
    
    Key Char: Reversible using KEY | KEY Dependent  |  
    
    types: Asymmetric vs Symmetric Enc.
    
    ASYMMETRIC: use different keys to  enc and d-crpyt
    
    while SYMMETRIC: use only the same key to enc and dcrypt
    
    ```
    Asymetric / (Public-key cryptography)
    
    hello ------------------> asfrheviu....df ----------------> hello
    				Private key                           Public Key
    ```
    
     **Common Asymmetric Encryption Algorithms:**
    
    1. RSA - Rivest–Shamir–Adleman
    2. ECDSA - Elliptic Curve Digital Signature Algorithm - ETH and BTC
    3. **EdDSA -** Edwards-curve Digital Signature Algorithm  - SOL
    
    How eliptic curves work - https://www.youtube.com/watch?v=NF1pwjL9-DE&
    
    ### Common eleptic curves
    
    1. secp256k1 - BTC and ETH
    2. ed25519 - SOL
    
    **Few usecases of public key cryptography -** 
    
    1. SSL/TLS certificates
    2. SSH keys to connect to servers/push to github
    3. Blockchains and cryptocurrencies
   
- Can a miner move money from one random address to another?
    
    No, only the user who holds the private key can sign the transaction. So even if a miner tries to `mimic` a transaction, other miners will reject the transaction signature.
    
- Which miner should I send my transaction to?
    
    When you hit "send" in your wallet, your transaction gets broadcast to whichever Bitcoin nodes your wallet is connected to. From there, it propagates across the entire network through a gossip protocol—each node that receives your transaction validates it and forwards it to the other nodes it's connected to. Within seconds, your transaction typically reaches most nodes on the network, including those run by miners.
    
- What if a miner doesnt include my transaction?
    
    It can happen. There can be blacklists/less incentive for a miner to include ur txn. That is why the concept of `tipping` exists
    
- Why would a person start a new miner? What do they get?
    
    When you propose a block, you add a txn to the top that gives you the block reward. This is how new BTC is added to the system. You can also earn tips based on who wants their txn to be included the fastest.
    
    **1. Block subsidy (the "block reward")**
    
    This is newly created bitcoin that gets awarded to whoever mines a valid block. It started at 50 BTC per block in 2009 and halves roughly every four years (every 210,000 blocks). Currently it's 3.125 BTC per block after the April 2024 halving. This subsidy is how all new bitcoin enters circulation.
    
    **2. Transaction fees**
    
    Every transaction in the block includes a fee paid by the sender. The miner who finds the block collects all the fees from every transaction they included. When the mempool is congested, fees can add up to a meaningful amount—sometimes rivaling or even exceeding the block subsidy during periods of high demand.
    
- Why wouldnt a miner always start to propose a block then? I would want to keep all the block reward for myself. I’ll just start a new miner and start proposing blocks every 1 minute.
    
    To be able to propose a block, you need to solve a `cryptographically hard` problem. 
    If there are 100 miners right now all having 4 cpus, they are all solving the same problem. 
    On average you will only be able to propose a block once in 100 blocks (simple probability).
    
    This is why people say BTC/crypto is bad for the environment because thousands of machines all around the world are solving the same futile problem just to be the `block leader`
    
    [1c457e44b6366b3191cca6f03a0c3e0f210919b5-1200x899.avif](attachment:255879c3-4804-4f93-92f2-ff7a31680bc1:1c457e44b6366b3191cca6f03a0c3e0f210919b5-1200x899.avif)
    
- What if two people propose a block at the same time?
    
    This happens occasionally and is totally normal—it's called a **chain split** or **temporary fork**.
    
    **What actually happens**
    
    Say miners A and B both find valid blocks at roughly the same height. Some nodes will hear about block A first, others will hear about block B first. Each node considers the first valid block it receives as the current tip of the chain and starts building on that. So now you briefly have two competing versions of the blockchain, each with a portion of the network working on it.
    
    **How it resolves**
    
    The rule is simple: the longest chain wins (technically, the chain with the most cumulative proof-of-work). As soon as another block gets mined on top of either A or B, that chain becomes longer. Nodes following the shorter chain will immediately abandon it and switch to the longer one. The "orphaned" block gets discarded—its transactions return to the mempool to be included in a future block.
    
    **Implications**
    
    This is why people wait for "confirmations" before considering a transaction final. One confirmation means it's in a block, but that block could still get orphaned. Six confirmations has become the informal standard for high-value transactions—at that depth, a reorg is extraordinarily unlikely without a deliberate 51% attack.
    
    ![Screenshot 2026-01-18 at 5.04.08 PM.png](attachment:d69bb8ad-4fd2-4177-a43e-2769e6ee36e7:Screenshot_2026-01-18_at_5.04.08_PM.png)
    
- How to forks get resolved?
    
    Eventually one fork will start to become longer, and broadcast this fork to the miners currently maintaining the other fork. The other miners will then accept the longer fork and discard their original fork. This happens automatically and rarely does a fork sustain for more than a few hours
    
- Can a transaction ever be reversed? Can you ever create a new fork that doesnt have a transaction that you want removed from the blockchain?
    
    ![Screenshot 2026-01-18 at 6.20.37 PM.png](attachment:ec8c60f1-1e17-443d-b8b9-207aee58e353:Screenshot_2026-01-18_at_6.20.37_PM.png)
    
    A blocks nonce is generated with the txn signature of the prev block attached. You will have to compete with everyone else creating the longest chain while you try your best to create a fork.
    
    ![Screenshot 2026-01-18 at 6.22.16 PM.png](attachment:926aad87-1fad-49c8-a4da-17e6eb0e9f06:Screenshot_2026-01-18_at_6.22.16_PM.png)
    
- Visualization
    
    https://andersbrownworth.com/blockchain/