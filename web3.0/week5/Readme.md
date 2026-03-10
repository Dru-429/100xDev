- Deploying Token
    
    Solana and Eth both works diffrently, while on Eth, deploying new contracts directly goes on-chain.
    
    While in Solana:
    
    - here smart contract called Programs.
    - They don’t store data, but can read and write accounts.
    - This account-based model makes it different from eth.
    - Here, deploying a token means talking to a pre-existing program rather than getting deployed on-chain.
- Solana Programs
    
    ```jsx
    						 complie
    Rust/Cpp/C -------------> BPF(Berkly packeet filter)
    
    runs on the solana runtime
    ```
    
    Framework to write Solana: Anchor
    
    ### Types of programs
    
    - **Native programs** — built into the Solana runtime (e.g., System Program, Stake Program, Vote Program)
    - **SPL (Solana Program Library) programs** — standard programs maintained by the community   (e.g., Token Program for fungible tokens, Associated Token Account Program, Token-2022)
    - **User-deployed programs** — custom programs anyone can deploy
- Clients CLI
    
    Solana CLI let’s u talk with the chain
    
- So, in the SOLANA System Program is like a bank that controls everything and basically transfers the amount based on the verified signature from our private key
- Owners on Solana
    - Every account —> has a Pub. key —> every key has an Owner —> owner’s program is the only program thats let u —>  modify the account’s data —> debit lamports from the account
    - Ownership is a fundamental concept in Solana’s Account model
    - Who is the owner == the **SYSTEM PROGRAM**
    - eg:
    
    ```jsx
    To transfer a sol from one to other: 
    
    sender(keys, amount) ---------> **SYSTEM PROGRAM** ---> recivers(pub key, amount recived)
    
    **System Program** is like a bank that controls everything and basically transfers the 
    amount based on the verified signature from our private key
    ```
    
    ![image.png](attachment:d8df0a91-e78e-47ca-9946-bc7526e97b6e:image.png)
    
    - In some case their could be some other owner, we will see in the future
- **System Program**
    
    The System Program is Solana's most fundamental built-in program. Its address is `11111111111111111111111111111111` (32 ones). 
    
    It's responsible for core operations on the network.
    
    ## What It Does
    
    The System Program handles four main things:
    
    - **1. Creating new accounts**
        
        Every account on Solana has to be created by the System Program. When you create an account, you specify the space (bytes) it needs, the lamports for rent, and which program will own it.
        
        - Code
            
            ```jsx
            import { Keypair, Transaction, SystemProgram, sendAndConfirmTransaction, LAMPORTS_PER_SOL, Connection } from "@solana/web3.js";
            
            const connection = new Connection("https://api.devnet.solana.com", "finalized");
            
            async function crateAccount() {
                const payer = Keypair.fromSecretKey(new Uint8Array([34,210,232,198,138,84,216,34,5,100,61,245,172,70,89,57,225,91,18,253,33,168,80,129,147,21,133,198,94,94,228,10,123,171,170,49,116,51,2,54,12,216,137,31,223,103,212,224,1,97,203,202,228,0,239,189,178,68,82,164,11,110,41,73]));
                // First create and fund a new account with no space
                const newAccount = Keypair.generate();
                console.log(payer.publicKey.toBase58())
                const fundTx = new Transaction().add(
                  SystemProgram.createAccount({
                    fromPubkey: payer.publicKey,
                    newAccountPubkey: newAccount.publicKey,
                    lamports: 0.1 * LAMPORTS_PER_SOL,
                    space: 0,
                    programId: SystemProgram.programId,
                  })
                );
                await sendAndConfirmTransaction(connection, fundTx, [payer, newAccount]);
                console.log("Funded account:", newAccount.publicKey.toBase58());
              }
              
              crateAccount()
            ```
            
        - Transaction
            
            https://explorer.solana.com/tx/iVotAewxSFA74ZcfmW7Dos9Byj749hP2W8qMEQaCkY17Bqa4DSEKRko8XzaKRvzgNDoZAWs3drixHwuu2BoHzmg?cluster=devnet
            
            ![Screenshot 2026-02-15 at 6.34.05 PM.png](attachment:683fc627-5962-4b71-a10a-92a1649d42e3:Screenshot_2026-02-15_at_6.34.05_PM.png)
            
    - **2. Transferring SOL**
        
        Moving SOL between wallets goes through the System Program since it owns all regular wallet accounts.
        
        - Code (cli)
            
            ```jsx
            solana-keygen new --outfile new-account.json --no-bip39-passphrase
            
            solana transfer $(solana-keygen pubkey new-account.json) 0.1 --allow-unfunded-recipient
            ```
            
        - Transaction
            
            https://explorer.solana.com/tx/4uY2FP2tHWg1jEq1XyySgr9Dr9pRTkp5cdhbb9koAnqYLJWE2AgwfYDbqzWvvWjK1pgFrKZjfX5UA1bmzGhNo1Um?cluster=devnet
            
            ![Screenshot 2026-02-15 at 6.17.57 PM.png](attachment:cf6b7b52-9ab3-40a3-84ef-237ddeaf5f67:Screenshot_2026-02-15_at_6.17.57_PM.png)
            
        
    - **3. Assigning ownership**
        
        When a new program needs to own an account (like when you create a token account), the System Program transfers ownership from itself to that program. Once ownership is transferred, the System Program can no longer modify that account.
        
        - Code
            
            ```jsx
            async function assignOwner() {
              const account = Keypair.generate();
              const newOwner = new PublicKey("NewOwnerProgramIdHere");
            
              // Fund the account first
              const fundTx = new Transaction().add(
                SystemProgram.transfer({
                  fromPubkey: payer.publicKey,
                  toPubkey: account.publicKey,
                  lamports: 0.01 * LAMPORTS_PER_SOL,
                })
              );
              await sendAndConfirmTransaction(connection, fundTx, [payer]);
              console.log("Funded account:", account.publicKey.toBase58());
            
              // Assign ownership to a new program
              const assignTx = new Transaction().add(
                SystemProgram.assign({
                  accountPubkey: account.publicKey,
                  programId: newOwner,
                })
              );
            
              // The account itself must sign
              const signature = await sendAndConfirmTransaction(connection, assignTx, [
                account,
              ]);
              console.log("Assign signature:", signature);
            }
            ```
            
        - Transaction
            - https://explorer.solana.com/tx/3L4GXXQBHgpFSsHTZvrcwtJwCvTztuisKNDvzUhiZgc5cPNyRMQuuGndA85GrP19zvYhD54VUcyHBUNdBWrxm9HR?cluster=devnet
            
            ![Screenshot 2026-02-15 at 6.28.16 PM.png](attachment:15d03c3a-613c-4636-986c-49578b22b7fc:Screenshot_2026-02-15_at_6.28.16_PM.png)
            
    - **4. Allocating space**
        
        
        It can allocate data space to an account that already exists but has zero bytes.
        
        - Code
            
            ```jsx
            import { Keypair, Transaction, SystemProgram, sendAndConfirmTransaction, LAMPORTS_PER_SOL, Connection } from "@solana/web3.js";
            
            const connection = new Connection("https://api.devnet.solana.com", "finalized");
            
            async function allocateSpace() {
                const payer = Keypair.fromSecretKey(new Uint8Array([34,210,232,198,138,84,216,34,5,100,61,245,172,70,89,57,225,91,18,253,33,168,80,129,147,21,133,198,94,94,228,10,123,171,170,49,116,51,2,54,12,216,137,31,223,103,212,224,1,97,203,202,228,0,239,189,178,68,82,164,11,110,41,73]));
                // First create and fund a new account with no space
                const account = Keypair.generate();
                console.log(payer.publicKey.toBase58())
                const fundTx = new Transaction().add(
                  SystemProgram.transfer({
                    fromPubkey: payer.publicKey,
                    toPubkey: account.publicKey,
                    lamports: 0.01 * LAMPORTS_PER_SOL,
                  })
                );
                await sendAndConfirmTransaction(connection, fundTx, [payer]);
                console.log("Funded account:", account.publicKey.toBase58());
                await new Promise(r => setTimeout(r, 30 * 1000));
                // Now allocate space to it
                const allocateTx = new Transaction().add(
                  SystemProgram.allocate({
                    accountPubkey: account.publicKey,
                    space: 100,
                  })
                );
              
                // The account itself must sign
                const signature = await sendAndConfirmTransaction(connection, allocateTx, [
                  account,
                ]);
                console.log("Allocate signature:", signature);
              }
              
              allocateSpace()
            ```
            
        - Transaction
            
            https://explorer.solana.com/tx/21dKF2NhsHHSxyQkdEtN4vi3aHduouB841rbStFQUWQpCTqTB48y7F7nuFSZENckLeR4hcd64C3ivpAucG5nvFUX?cluster=devnet
            
            ![Screenshot 2026-02-15 at 6.31.47 PM.png](attachment:0c6374ea-2e58-46fa-80ae-6198e072aba7:Screenshot_2026-02-15_at_6.31.47_PM.png)