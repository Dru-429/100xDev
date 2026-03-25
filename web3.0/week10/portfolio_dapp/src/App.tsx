import React, { FC, useMemo } from 'react';
import { ConnectionProvider, WalletProvider } from '@solana/wallet-adapter-react';
import { WalletAdapterNetwork } from '@solana/wallet-adapter-base';
import { UnsafeBurnerWalletAdapter } from '@solana/wallet-adapter-wallets';
import {
  WalletModalProvider,
  WalletDisconnectButton,
  WalletMultiButton
} from '@solana/wallet-adapter-react-ui';
import { clusterApiUrl } from '@solana/web3.js';

// Default styles that can be overridden by your app
import '@solana/wallet-adapter-react-ui/styles.css';

const App = () => {

  const endpoint = "https://mainnet.helius-rpc.com/?api-key=8fa95f21-efe0-4b05-becd-e33fc50661e8"

  return (
    <ConnectionProvider endpoint={endpoint}>
      <WalletProvider wallets={[]} autoConnect>
        <WalletModalProvider>
          <div className='flex flex-end gap-2'>
            <WalletMultiButton />
            <WalletDisconnectButton />
          </div>
          { /* Your app's components go here, nested within the context providers. */}
        </WalletModalProvider>
      </WalletProvider>
    </ConnectionProvider>
  )
}

function TopBar() {
  const { publicKey }  = ;

  return <div>

  </div>
}


export default App