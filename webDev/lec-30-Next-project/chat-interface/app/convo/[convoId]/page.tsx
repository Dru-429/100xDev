import { prisma } from '@/lib/db'

const page = async ({
  params
}: {
  params: {
    convoId: string
  }
}) => {
  // const params = useParams<{ convoId: string }>()

  const convoId = params.convoId
  const messages = await prisma.message.findMany({
    where: {
      convoId
    }
  })


  return (
    <div className='relative flex flex-col min-h-screen justify-between text-center p-3 md:p-10'>
      <div className="max-w-5xl">
        History Appears here
        {messages.map(message => (
          <div
            key={message.id}
            className={`flex ${
              message.role === 'User' ? 'justify-end' : 'justify-start'
            }`}
          >
            <div
              className={`max-w-[80%] rounded-2xl px-4 py-3 whitespace-pre-wrap break-words ${
                message.role === 'User'
                  ? 'bg-blue-600 text-white'
                  : 'bg-zinc-800 text-zinc-100'
              }`}
            >
              {message.message}
            </div>
          </div>
        ))}
      </div>
      <div className='w-full flex justify-center'>
        <div className='relative bottom-10 w-full md:w-[80%] flex gap-5 justify-center'>
          <input
            type='text'
            placeholder={"..."}
            className='w-full max-w-4xl md:w-[80vw] bg-zinc-800 px-4 py-2 rounded-2xl'
          />
          <button
            className='bg-zinc-800 px-4 cursor-pointer py-2 border-zinc-700 rounded-xl'
          >
            Send
          </button>
        </div>
      </div>
    </div>
  )
}

export default page
