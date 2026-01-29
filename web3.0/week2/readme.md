- HD Wallet
    
    Hierarchical Deterministic Wallet
    
    ---
    
    Here, we can generate a tree of public-private key pairs from a SINGLE SEED 
    
    Prob: Storage —> we have to store all the pairs to have multiple wallets 
    
    Sol:  BIP-32
    
    [Bitcoin Improvement Proposal](https://www.ledger.com/academy/what-is-a-bitcoin-improvement-proposal-bip) 32 (BIP-32) 2012. By Pieter Wuilla Bitcoin core dev
    
     BIP-32 introduced a hierarchical tree-like structure for wallets that allowed you to manage multiple accounts much more easily than was previously possible.
    
     It’s essentially a standardized way to derive private and public keys from a master seed.
    
    Means each user got one master seed from which they can generate multiple private-public key pairs. 
    
- ETH
    - Bitcoin: solve a single prob i.e —> a new currency (BTC) that hopefully has some value (digital gold/inflation hedge).
        - It does not support:  Buying stokes |  stablecoins | Custom tokens | Lending/Borrowing
        - So many others also came along to solve the issues, see the prob with this, each of them solves one or two issues, but they are hard to build
        - Think about it, can we make our own coin like them
            
            ![image.png](attachment:ce6f6147-72a1-4f01-bcb3-1e40422472e8:image.png)
            
    - Then came ETH ~ 2014
    - They said we provide u a simpler way to make D-apps,
    - Ethereum allows people to write a smart contract that helps them to make D-apps
    - SMART CONTRACTS
        
        Smart contracts are `executable code` that is stored on chain and can execute `on-chain` (machines of the miners). 
        
        The `code` is written in a language called `solidity` and it executes on a virtual machine on the miner called an `Ethereum virtual machine` (EVM).
        
        So the ETH blockchain stores every users ETH balance as one use case, but other than that 100s of use cases can be written and deployed on the ETH blockchain.
        
        For example, https://app.uniswap.org/ is a DEX that lets you swap one token for another.
        
- Seeds to Private Keys
    
    ```jsx
                          Mnemonic (12 words)
                                   |
                                   |
                                   |
                                   v
    								          Seed (512 bytes)
                                (BIP-39)
    																|
            ________________________|________________________
            |                                               |
            | m/44'/60'/0                                   | m/44'/60'/1
            v                                               v
     seed of wallet 1                                seed of wallet 1
            |                                               |
            |                                               |
            v                                               v
    public/private keypair                          public/private keypair
    ```
    
    - Mnemonics:
    Human-readable seed phrase, a string of words used to generate a cryptographic seed phrase
        - BIP-39 (Bitcoin Improvement Protocol 39) defines how mnemonic phrases are generated and converted into a seed.
        - Ref -  https://github.com/bitcoin/bips/blob/master/bip-0039/english.txt
        - This is the list of the words that are used
        - So we use 12 words for each seed
    - Seed:
        - A 64-byte (512 bits) binary value derived from the mnemonics.
        - Then that seed is used to derive the seed of wallets( each seed futher use to take private and public keys )
    - Derivation Path:
        - A systematic way to derive various keys from a master seed
        - WHY WE NEED IT?
        - They allow users to recreate the same set of addresses and private keys from the seed across different wallets, ensuring interoperability and consistency.
        - (for eg: if you ever want to port from Phantom to Backpack)
        - A derivation path is typically expressed in a format like
            - `m / purpose' / coin_type' / account' / change / address_index`.
            - **`m`**: Refers to the master node, or the root of the HD wallet.
            - **`purpose`**: A constant that defines the purpose of the wallet (e.g., `44'` for BIP44, which is a standard for HD wallets).
            - **`coin_type`**: Indicates the type of cryptocurrency (e.g., `0'` for Bitcoin, `60'` for Ethereum, `501'` for solana).
            - **`account`**: Specifies the account number (e.g., `0'` for the first account).
            - **`change`**: This is either `0` or `1`, where `0` typically represents external addresses (receiving addresses), and `1` represents internal addresses (change addresses).
            - **`address_index`**: A sequential index to generate multiple addresses under the same account and change path.
        
    
    ```jsx
    import nacl from "tweetnacl";
    import { generateMnemonic, mnemonicToSeedSync } from "bip39";
    import { derivePath } from "ed25519-hd-key";
    import { Keypair } from "@solana/web3.js";
    
    const mnemonic = generateMnemonic();
    const seed = mnemonicToSeedSync(mnemonic);
    for (let i = 0; i < 4; i++) {
      const path = `m/44'/501'/${i}'/0'`; // This is the derivation path
      const derivedSeed = derivePath(path, seed.toString("hex")).key;
      const secret = nacl.sign.keyPair.fromSeed(derivedSeed).secretKey;
      console.log(Keypair.fromSecretKey(secret).publicKey.toBase58());
    }
    ```
    
- D-App
    
    Decentralized applications 
    
    ---
    
    - What are Dapps?
        - Apps that build on Solana and run on a distributed network rather than a centralized server.
        - Solana D-app = Smart contract( Rust )  + Frontend
        - Backend Logics = Storing data, processing data, rules, etc happens on the BLOCKCHAIN
        - WHY SOLANA = Prioritize speed | low costs
        - It uses a proof-of-stake consensus combined with a mechanism called proof-of-history, which timestamps transactions to enable parallel processing.
        - That's how Solana handles thousands of transactions per second + fees under a cent
    - How to create a dapp?
        - figure out the need for it USECASE
        1. Smart contract (or program) - Usually written in Rust on Solana
        2. Client - A typescript library that you can create that makes it easy to interact with the contract
        3. Frontend (in React/NextJS) that lets your users interact with your contract.