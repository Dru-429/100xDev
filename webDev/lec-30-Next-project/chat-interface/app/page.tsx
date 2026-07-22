
export default function Home() {
  return (
    <div className="flex flex-col flex-1 items-center justify-center bg-zinc-950 text-zinc-50">
      <main className="relative max-w-screen min-h-screen p-10 flex flex-col justify-between">
        <div>
          hi
        </div>
        <div className="relative bottom-10 w-full md:w-[80%]">
          <input 
            type="text" 
            placeholder="Type what u want to ask..."
            className="w-full "
          />
        </div>
      </main>
    </div>
  );
}
