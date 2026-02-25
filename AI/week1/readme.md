---

![image.png](attachment:447a1540-07be-4a59-9d45-c5f2ff8c0e94:image.png)

Knowledge —> Explitiate 

                |—> Implicitice 

- Intelligence: the ability to learn a wide range of things
- What is AI: make a machine to do something that requires intelligence
- 1st Attempt:
    - Rule-based systems: eg. if temp= 100F —> means fever
    - Problem of rules: it would just don’t able to understand the CONTEXT
- 2st Attempt: Data + statistical
    - show machine thousands of  egs. and let it fig out itself
    - Show Many egs. —> Machine makesa  guess —> tell it if R or W —> Machine adjusts it self → repeat Million time
    - Like how we learn cycling
- DEEP LEARNING: here we try to mimic the human brain, like a neural network, where each neural hits by some action to prod result.
    - AI WINTER: the time period where peopke stop working on Ai, as they dont have dayssnd computation
- So the problem with AI is they don’t understand the Language like what is apple ⇒ it is a round fruit, or a trillion dolar company ,etc.
- So we got something called the NLP( natural language processing ) 
 eg: if New is followed by York then it is a city
- Vectors: then we got into VECTORS
    - Dimensions of Meaning
        
        
        | Word | Royalty | Gender (M) | Edibility |
        | --- | --- | --- | --- |
        | King | 0.98 | 0.95 | 0.01 |
        | Queen | 0.97 | 0.05 | 0.02 |
        | Apple | 0.02 | 0.00 | 0.94 |
    - VECTORS: here we a combination on numbers to represent a word that denotes on the graphs (but it has a lot of dimensions like 100s-1000s of it), and every D means something different.
    - **Embeddings**: it means converting a word into numbers  ⇒ Results as words as a position in the dimensional space
    - And machines work really well with the numbers
    
    ```
    ^ Dimension B
    |
    |
    |
    |       .king   .queen                                        . Apple (Corp)
    |
    |
    |      . man    .woman
    |
    |
    |                                                       . car
    |                                                            . bicycle
    |
    |                                                      . apple
    |                                                           . orange
    |       . cat   . dog
    |
    +----------------------------------------------------------------------> Dimension A
    ```
    
    - Eg:
        - King -Man + Female = Queen
    - Words with more than one meaning wala issue ko solve kra kaise:
    - Using RNN systems: 
    Using the embedding system, it processes word by word, so the meaning of a word is based on the closest meaning of other words in the sentence:
        - eg: “I went to the bank to put my money “ vs “I went to the bank to sit near the rivers”
        - WHY RNN FAILS THEN: 
        In big seq it can't keep up —> FORGETTING issues
        - LSTM( long short term memory) model : 
        Here we add a gate  that checks if a word just doesn’t make sense it, it wouldn’t remember it(like the, to, etc), but still the issue remains the same for a bigger context
    
    **. Transformers and the Attention Mechanism**
    **The Shift:** Instead of reading word-by-word (Sequential), Transformers look at every word in a sentence simultaneously (Simultaneous).
    
    • 
    **Attention:** The model "attends" to the most relevant words to build context.
    
    • **Attention in Action (The "It" Problem):**
        ◦ *Scenario A:* "The animal didn't cross the street because **it** was too **tired**." (Attention connects "it" to "animal") .
    
        ◦ *Scenario B:* "The animal didn't cross the street because **it** was too **wide**." (Attention connects "it" to "street") .
    
    • 
    **Benefits:** No forgetting, parallel processing (much faster), and deep context understanding.
    
    **7. How Modern LLMs (ChatGPT) Work**
    • 
    **The Engine:** A massive neural network based on the Transformer architecture.
    
    • 
    **The Knowledge:** Trained on trillions of words from the public internet.
    
    • 
    **The Objective:** Predict the most likely next word in a sequence.
    
    • 
    **Why Prediction creates "Understanding":** To predict correctly, the model must internalize grammar, factual knowledge, and logic.
    
    • 
    **Generative Loop:** It predicts a word, adds it to the input, and predicts the next one iteratively.
    
    **8. The Scaling Laws & Future Trends**
    • 
    **Emergent Capabilities:** As models get larger (more Data, Parameters, and Compute), they spontaneously develop skills they weren't specifically trained for, like reasoning and coding.
    
    • 
    **Foundation Models:** We have shifted from "Task-Specific AI" (separate models for translation, summary, etc.) to "General-Purpose AI" (one massive model for everything).git add .
    