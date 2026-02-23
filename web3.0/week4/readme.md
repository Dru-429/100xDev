- Types of Accounts in Solana
    
    There are many types of accounts in Solana, but mainly we gonna see three types that are: 
    
    - Normal accounts: normal wallets have lamports, public keys and dont have any other data.
    - Program Accounts: have executable code/ smart contracts, lamports, KEY data,
    - Data Accounts: has lamports and data. it further divided into two
        - Normal Data acc.
        - Program-derived addresses. : it doesn’t have any Private keys.
    - Solana
- Solana Clusters
    
    ![image.png](attachment:7e2ca027-a533-4421-aff0-29c4b4d4878a:image.png)
    
    - Mainnet cluster:  here the main network where it all runs
    - Devnet cluster: basically a test cluster for trying out our smart contract & also here me can send us an airdrop, and do anything, as here it won’t be related to our actual coins, just for test purposes
    - Testnet cluster: a test net cluster
    
    Stability of clusters:  Mainnet >> devnet >>>> Test net
    
    ### Solana RPC Servers
    
    means remote procedural call, generally it means making a call to a function remotely at the server 
    
    eg: as it happens in GraphQL, here we write a function to call rather than using get post as we do in the REST 
    
     
    
    RPC servers are your gateway to talk to the solana validators.
    
    At a high level: **validators secure the network**, **RPC servers help you talk to the network**. They often run on the same machine, but they’re doing very different jobs.
    
    **What they do**
    
    - Expose **APIs** (JSON-RPC, WebSocket) for:
        - Submitting transactions
        - Querying account data
        - Reading blocks, signatures, balances
    - Serve wallets, dApps, indexers, bots
    
    **Why they matter**
    
    - They’re how *users and apps* interact with Solana
    - Without RPCs, the chain exists but is basically inaccessible
    
    **Key traits**
    
    - No role in consensus
    - No voting, no block production
    - Optimized for **read-heavy workloads**
    - Can be rate-limited, cached, or indexed
    - Usually monetized via SaaS (Helius, QuickNode, Triton, etc.)
    
    ![image.png](attachment:0f4ef93f-9e51-47d5-9e91-b5d19fabf1c5:image.png)
    
- Web2 Data Model
    
    Here we're gonna compare DATA STORING in web2 & web 3’
    
    - Web2:  BK token eg.
        - BK has a token system, which is their own currency, meaning they store in a Classical DB manner, may be using sql or no-sql db.
    - Solana Data model:
        - Token program:
            
            ![image.png](attachment:ebcd6a24-3a92-461f-b521-203dd5942dc8:image.png)
            
            - For token saving, suppose trump lunching a new coin, So  —> first they deploy a server on Solana —> Called the MINT account —> then it have a ATA(associated token account) —> when dru buys some trump coin, a new ATA account made related to the mint account, where it stores my data info about how much coin I have
            - means if there are all N no. of users on that chain means their are N no. of ATAs.
        - Creating a new Account
        
        ![image.png](attachment:6848f161-8fc8-4b91-a15b-1d91fe318fd0:image.png)
        
        - Every ATA  address has the mint bits included, but the Mint account doesn’t have any ATAs address
        - ATAs are not Pda
        - 

![image.png](attachment:337270e5-9c9d-4625-b40d-4a652176969f:image.png)