Week 3 - Solana Jargon

- Lamports
    - 1 Lamport —> the smallest unit of SOL
    - 1 SOL = 10^9 lamports
    - On Blockchain —> it stores in Lamports, not SOL
        - Why —> We should never store decimals in a DB espeicaly in Fainace because of precision error, mean last numbers in decimals get round-off.
- Accounts on Solana
    
    ![image.png](attachment:3411fb73-b255-43fc-aa15-982a4ac30f78:image.png)
    
- Native token
    - Native tokens: Are the built-in currency i.e hardcoded in the protocol of the blockchain, eg, SOL for Solana.
    - The rest of it is built on top of it by deploying the smart contract.
    - eg.: SOL is the native token of Solana, ie, why we see lamport on calling the CRUD op to the server.
    - How is it different from the custom token?
        
        
        | **Feature** | **Native Token (e.g., SOL)** | **Custom Token (e.g., USDC, SPL tokens)** |
        | --- | --- | --- |
        | **Origin** | Hardcoded into the protocol's base layer. | Created by deploying a **smart contract**  on the network. |
        | **Infrastructure** | Every validator and node understands it natively. | The network doesn't inherently "know" about them; they rely on program rules, defined in the smart contract. |
        | **Creation/Transfer** | No smart contract required for basic operations. | Rules (supply, decimals, logic) are defined by the specific program. |
        | **Transfer Type** | A **system-level** operation. | Requires **invoking a program** (like the SPL Token Program). |
        | **Transaction Fees** | Used to pay for gas and network fees. | **Cannot** be used for transaction fees; you still need the native token. |
        | **Primary Use** | Staking, securing the network, and unit of account. | Defined by the creator (e.g., stablecoins, utility tokens). |
- Gas = Transaction fees
    - **The Purpose of Gas:** Gas acts as a pricing mechanism for computation (verifying signatures, updating states) to prevent network spam and provide an economic disincentive for abuse.
    
    TYPES:
    
    - **Base Fee (Fixed):**
        - Every signature on a transaction costs a static **5,000 lamports** (0.000005 SOL).
        - This fee is protocol-defined and does not change based on network congestion.
    - Compute Units (CU):
        - These measure the computational weight of a transaction (e.g., math operations, account reads/writes).
        - The default budget is **200,000 CU**, with a maximum of **1.4 million CU**; exceeding this budget causes the transaction to fail.
        - Using the `SetComputeUnitLimit` instruction is recommended to inform the scheduler of the transaction's size.
    - Priority Fee (Optional):
        - This is a market-driven fee priced in **micro-lamports per compute unit**.
        - Users can increase this fee during high-demand periods (like NFT mints) to get their transactions processed faster.
    - Fee Distribution:
        - **5**0% of the total fee is burned, creating a mild deflationary pressure on the SOL supply.
        - The remaining **50% is paid to the validator** that processed the transaction.
    - Why Fees Remain Low**:**
        - Solana's high throughput allows for **thousands of transactions per second**, compared to Ethereum’s 15–30.
        - This high supply of block space relative to demand keeps the costs minimal.
    - Why half of the Gas fees get burned?
        
        
    
    eg: 
    
    | **Component** | **Calculation** | **Cost in Lamports** |
    | --- | --- | --- |
    | **Amount to Send** | $0.01 \text{ SOL} \times 1,000,000,000$ | $10,000,000$ |
    | **Base Fee** | $1 \text{ signature} \times 5,000 \text{ lamports}$ | $5,000$ |
    | **Priority Fee** | $200,000 \text{ CU} \times 5 \text{ micro-lamports/CU}$ | $1,000^*$ |
    | **Total Fee** | $\text{Base Fee} + \text{Priority Fee}$ | **$6,000$** |
- Stable coin
    
    Custom tokens that are pegged to a currency 
    
    ---
    
    -