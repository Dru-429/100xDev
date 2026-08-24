'use client'
import { signIn, useSession } from 'next-auth/react'
import Image from 'next/image'

export default function Home () {
  const { data: session, status } = useSession()

  return (
    <div className='flex flex-col flex-1 items-center justify-center bg-zinc-50 font-sans dark:bg-black'>
      Hi there
      {status === 'authenticated' ? (
        <div>
          Hi {session.user?.email}
          <button>Logout</button>
        </div>
      ) : (
        <div>
          <button onClick={signIn}>Sign in</button>
          <button>Sign up</button>
        </div>
      )}
    </div>
  )
}
