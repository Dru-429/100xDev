import axios from "axios"

async function getData() {
  const resp = await axios.get("https://week-13-offline.kirattechnologies.workers.dev/api/v1/user/details")
  return resp.data
}

export default async function usercard2 () {
  const data = await getData()
  return(
    <div>
      {data.name}
    </div>
  )
 }   