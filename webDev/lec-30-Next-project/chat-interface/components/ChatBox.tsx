'use client'

import { useState } from 'react'

export default function ChatBox () {
  const [message, setMessage] = useState('start typing here')

  return (
    <div className='relative bottom-10 w-full md:w-[80%] flex gap-5 justify-center'>
      <input
        onChange={e => {
          setMessage(e.target.value)
        }}
        type='text'
        placeholder={message}
        className='w-full max-w-4xl md:w-[80vw] bg-zinc-800 px-4 py-2 rounded-2xl'
      />
      <button
        onClick={() => {}}
        className='bg-zinc-800 px-4 cursor-pointer py-2 border-zinc-700 rounded-xl'
      >
        Send
      </button>
    </div>
  )
}
